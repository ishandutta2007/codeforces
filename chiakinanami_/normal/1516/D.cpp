#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> prime;
bool isPrime[100002];

int n, q;
int arr[100002];
int nxt[100002];
int sparse[100002][20];

vector<int> primes[100002];
vector<int> occurence[100002];
int lim[100002];

multiset<int> mst;

int main(){
    for(int i=2; i<=100000; i++) isPrime[i] = 1;
    for(int i=2; i*i<=100000; i++){
        if(!isPrime[i]) continue;
        prime.push_back(i);
        for(int j=i*i; j<=100000; j+=i) isPrime[j] = 0;
    }

    scanf("%d %d", &n, &q);
    for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
    for(int i=1; i<=n; i++){
        for(auto x: prime){
            if(arr[i] % x == 0){
                primes[i].push_back(x);
                while(arr[i] % x == 0) arr[i] /= x;
            }
        }
        if(arr[i] > 1) primes[i].push_back(arr[i]);
        for(auto x: primes[i]) occurence[x].push_back(i);
    }

    for(int i=1; i<=n; i++) lim[i] = n+1;
    for(int i=1; i<=100000; i++){
        for(int j=0; j<(int)occurence[i].size() - 1; j++){
            int x = occurence[i][j];
            lim[x] = min(lim[x], occurence[i][j+1]);
        }
    }

    int r = 1;
    mst.insert(lim[1]);
    for(int l=1; l<=n; l++){
        if(l>r) r++, mst.insert(lim[r]);
        while(r<n && r+1 < *mst.begin()) mst.insert(lim[++r]);
        nxt[l] = r+1;
        mst.erase(mst.find(lim[l]));
    }

    for(int i=1; i<=n; i++) sparse[i][0] = nxt[i];
    for(int d=1; d<20; d++) for(int i=1; i<=n; i++){
        sparse[i][d] = sparse[sparse[i][d-1]][d-1];
        if(!sparse[i][d]) sparse[i][d] = n+1;
    }
    while(q--){
        int l, r;
        scanf("%d %d", &l, &r);
        int ans = 0;
        for(int i=19; i>=0; i--){
            if(sparse[l][i] <= r){
                ans += (1<<i);
                l = sparse[l][i];
            }
        }
        printf("%d\n", ans+1);
    }
}