#include<bits/stdc++.h>
#define int long long
using namespace std;
int chet[1<<20], nechet[1<<20];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    chet[0]++;
    int ans = 0, X=0;
    for (int i=0; i < n; i++){
        X ^= v[i];
        if (i % 2 == 0){
            ans += nechet[X];
            nechet[X]++;
        }
        else{
            ans += chet[X];
            chet[X]++;
        }
    }
    cout << ans;
}