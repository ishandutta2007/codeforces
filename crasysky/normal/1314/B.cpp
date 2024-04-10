#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define sit set< pr >::iterator
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int N=2e6+6;
int f[N][20],s[N];
void upd(int &x,int y){ x=max(x,y); }
void solve(int rt,int l,int r,int d){
    if (r-l+1==2){
        if (s[r]-s[l-1]) rep(i,0,s[r]-s[l-1]) f[rt][i]=1;
        return;
    }
    int m=l+r>>1;
    solve(rt<<1,l,m,d+1),solve(rt<<1|1,m+1,r,d+1);
    int sl=s[m]-s[l-1],sr=s[r]-s[m];
    rep(ls,0,min(d,sl))
        rep(rs,0,min(d-ls,sr)){
            upd(f[rt][ls+rs],f[rt<<1][ls]+f[rt<<1|1][rs]+(ls+rs>0)+2*(ls+rs!=sl+sr));
            if (ls<sl) upd(f[rt][ls+rs],f[rt<<1][ls+1]+f[rt<<1|1][rs]+2+(ls+rs+1!=sl+sr));
            if (rs<sr) upd(f[rt][ls+rs],f[rt<<1][ls]+f[rt<<1|1][rs+1]+2+(ls+rs+1!=sl+sr));
        }
}
int main(){
    int n,k; scanf("%d%d",&n,&k);
    rep(i,1,k){ int a; scanf("%d",&a); ++s[a]; }
    rep(i,1,(1<<n)) s[i]+=s[i-1];
    solve(1,1,1<<n,0); cout<<f[1][0]+(k>0)<<endl;
    return 0;
}