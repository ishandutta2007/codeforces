#include <bits/stdc++.h>
using namespace std;

int ask(int x){
    cout << "? " << x+1 << endl;
    char c; cin >> c;
    if(c == 'Y') return 1;
    return 0;
}

void reset(){
    cout << "R" << endl;
}

void print(int x){
    cout << "! " << x << endl;
    exit(0);
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k; int pk = k;
    vector<int> cnt(n, 0);
    int ans = 0, totcnt = 0;
    if(k != 1) k /= 2;
    for(int i = 0; i<n/k; i++){
        for(int j = i+1; j<n/k; j++){
            for(int a = 0; a<k; a++) cnt[i*k+a] += ask(i*k+a);
            for(int a = 0; a<k; a++) cnt[j*k+a] += ask(j*k+a);
            totcnt += 2*k;
            reset();
        }
    }
    if(pk != 1) assert(totcnt == 2*n*n/pk-n);
    for(int i = 0; i<n; i++) if(!cnt[i]) ans++;
    print(ans);
}