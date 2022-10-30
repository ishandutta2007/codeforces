#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define sit set<int>::iterator
#define pb push_back
#define ll long long
using namespace std;
const int P=998244353;
int fpw(int x,int y){
    if (y==0) y=P-1;
    int s=1;
    for (;y;y>>=1,x=(ll)x*x%P) if (y&1) s=(ll)s*x%P;
    return s;
}
signed main(){
    int n,m,l,r; cin>>n>>m>>l>>r;
    int a=(l&1)&&(r&1)?(r-l+2)/2:(r-l+1)/2,b=r-l+1-a;
    if ((n*m)&1) cout<<fpw(a+b,(ll)n*m%(P-1))<<endl;
    else cout<<(ll)(fpw(a+b,(ll)n*m%(P-1))+fpw(((ll)b-a+P+P)%P,(ll)n*m%(P-1)))*(P+1)/2%P;
    return 0;
}