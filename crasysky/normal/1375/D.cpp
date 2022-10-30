#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6,INF=1e9;
int n,a[N],b[N],t[N];
int mex(){
    rep(i,0,n) t[i]=0;
    rep(i,1,n) ++t[a[i]];
    rep(i,0,n) if (!t[i]) return i;
}
int main(){
    int T; cin>>T;
    while (T--){
        int m=0; scanf("%d",&n);
        rep(i,1,n) scanf("%d",&a[i]);
        int x=mex();
        while (x<n){
            b[++m]=x+1,a[x+1]=x;
            x=mex();
        }
        rep(i,1,n)
            if (a[i]!=i-1){
                rep(j,i+1,n)
                    if (a[j]==i-1){
                        b[++m]=j,a[j]=mex();
                        break;
                    }
                b[++m]=i,a[i]=mex();
            }
        cout<<m<<endl;
        rep(i,1,m) printf("%d ",b[i]);
        cout<<endl;
    }
    return 0;
}