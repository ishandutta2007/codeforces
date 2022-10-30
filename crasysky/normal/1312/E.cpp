#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define sit set<int>::iterator
#define ll long long
using namespace std;
const int N=502;
int a[N],f[N][N],g[N];
int main(){
    int n; cin>>n;
    rep(i,1,n){ cin>>a[i]; f[i][i]=a[i]; }
    per(l,n,1)
        rep(r,l+1,n)
            rep(i,l,r-1)
                if (f[l][i]&&f[i+1][r]&&f[l][i]==f[i+1][r])
                    f[l][r]=f[l][i]+1;
    rep(i,1,n){
        g[i]=i;
        rep(j,0,i-1)
            if (f[j+1][i]) g[i]=min(g[i],g[j]+1);
    }
    cout<<g[n]<<endl;
}