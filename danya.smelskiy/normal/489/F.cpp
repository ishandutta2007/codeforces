#include <bits/stdc++.h>
using namespace std;


long long n,m,md;
long long kol[1005];
string s;
long long ans[1005][1005];
bool used[1005][1005];
long long get(int z,long long x,long long y){
    if (used[x][y]) return ans[x][y];
    if (z==n+1) {
        return (!x && !y) ? 1 : 0;
    }
    long long res=0;
    if (x>=2) res=(res+(x)*(x-1)/2*get(z+1,x-2,y+2))%md;
    if (y>=2) res=(res+(y)*(y-1)/2*get(z+1,x,y-2))%md;
    if (x && y) res=(res+x*y*get(z+1,x-1,y))%md;
    used[x][y]=true;
    ans[x][y]=res;
    return res;
}
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a=0,b=0;
    cin>>n>>m>>md;
    for (int i=1;i<=m;++i) {
        cin>>s;
        for (int j=0;j<n;++j)
            if (s[j]=='1') ++kol[j];
    }
    for (int i=0;i<n;++i)
        if (kol[i]==0) ++a;
        else if (kol[i]==1) ++b;
    cout<<get(m+1,a,b);
}