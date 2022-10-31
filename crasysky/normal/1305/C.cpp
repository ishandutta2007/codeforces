#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define sit set<int>::iterator
#define ll long long
using namespace std;
const int N=1e3+3,INF=1e9;
int a[1000006],c[N],c2[N],m;
int fpw(int x,long long y){
    int s=1; for (;y;y>>=1,x=x*x%m) if (y&1) s=s*x%m;
    return s;
}
int main(){
    int n; scanf("%d%d",&n,&m);
    rep(i,1,n){
        scanf("%d",&a[i]); ++c[a[i]%m];
    }
    rep(i,0,m-1) if (c[i]>1){ cout<<0<<endl; return 0; }
    sort(a+1,a+1+n);
    long long f=0;
    per(i,n,1){
        rep(j,0,a[i]%m-1) f+=c2[j];
        ++c2[a[i]%m];
    }
    int ans=1;
    for (int i=0;i<m;++i)
        for (int j=i+1;j<m;++j)
            ans=ans*fpw(j-i,(ll)c[i]*c[j])%m;
    cout<<(f&1?(m-ans)%m:ans)<<endl;
}