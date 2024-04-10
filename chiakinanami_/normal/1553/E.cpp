#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n, m;
int arr[300002];
vector<int> cand;
vector<int> ans;

int counter[300002];
int tarr[300002];
bool visited[300002];

bool able(int x){
    for(int i=1; i<=n; i++){
        tarr[i] = (arr[i] + x) % n;
        if(!tarr[i]) tarr[i] = n;
        visited[i] = 0;
    }

    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        visited[i] = 1;
        int tmp = tarr[i];
        while(!visited[tmp]){
            cnt++;
            visited[tmp] = 1;
            tmp = tarr[tmp];
        }
    }
    return cnt <= m;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
        cand.clear();
        ans.clear();

        for(int i=0; i<=n; i++) counter[i] = 0;
        for(int i=1; i<=n; i++){
            int tmp = (i - arr[i] + n) % n;
            counter[tmp]++;
        }
        for(int i=0; i<n; i++) if(n - m*2 <= counter[i]) cand.push_back(i);
        for(auto x: cand){
            if(able(x)) ans.push_back(x);
        }
        printf("%d ", (int)ans.size());
        for(auto x: ans) printf("%d ", x);
        puts("");
    }
}