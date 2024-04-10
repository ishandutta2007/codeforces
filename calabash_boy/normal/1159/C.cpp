#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+ 100;
int b[maxn];
int g[maxn];
int n;
int m;
int main(){
    cin>>n>>m;
    int b_max = -1;
    long long b_tot = 0;
    for (int i=0;i<n;i++){
        cin>>b[i];
        b_tot += b[i];
        b_max = max(b_max,b[i]);
    }
    sort(b,b+n);
    int min_g = INT_MAX;
    for (int i=0;i<m;i++){
        cin>>g[i];
        min_g = min(min_g,g[i]);
    }
    cerr<<b_max<<" "<<min_g<<endl;
    if (b_max > min_g){
        return puts("-1"),0;
    }
    long long ans = b_tot *m;
    int cnt = 0;
    for (int i=0;i<m;i++){
        if (g[i] == b_max)continue;
        cnt ++;
        ans += max(0,g[i] - b_max);
    }
    if (cnt == m){
        ans += b[n-1] - b[n-2];
    }
    cout<<ans<<endl;
    return 0;
}