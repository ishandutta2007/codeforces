#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int P=998244353;
int pw2(int y){
    if (y<0) y+=P-1; int x=2;
    int s=1; for (;y;y>>=1,x=(ll)x*x%P) if (y&1) s=(ll)s*x%P;
    return s;
}
int k,c[100];
ll a[100];
void calc(int t,ll x){
    if (t>k){ ++c[__builtin_popcountll(x)]; return; }
    calc(t+1,x),calc(t+1,x^a[t]);
}
int m,C[100][100];
ll bs[100];
bool ins(ll x){
    per(i,m-1,0)
        if (x>>i&1){
            if (bs[i]){
                if (!(x^=bs[i])) return false;
            }
            else{
                per(j,i-1,0)
                    if (bs[j]&&(x&(1LL<<j))) x^=bs[j];
                bs[i]=x;
                rep(j,i+1,m-1)
                    if (bs[j]&&(bs[j]&(1LL<<i))) bs[j]^=bs[i];
                return true;
            }
        }
    return false;
}
int main(){
    int n,b=0; scanf("%d%d",&n,&m);
    rep(i,1,n){
        ll x; scanf("%lld",&x); b+=ins(x);
    }
    if (b<=m/2){
        rep(i,0,m-1)
            if (bs[i]) a[++k]=bs[i];
        calc(1,0);
        rep(i,0,m)
            printf("%d ",((ll)c[i]*pw2(n-k))%P);
    }
    else{
        rep(i,0,m-1)
            if (!bs[i]){
                int t=0; ++k;
                rep(j,0,m-1)
                    if (bs[j]){
                        a[k]|=(bs[j]>>i&1)<<t;
                        ++t;
                    }
                a[k]|=1LL<<(b+k);
            }
        calc(1,0);
        rep(i,0,m){
            C[i][0]=1;
            rep(j,1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
        }
        rep(i,0,m){
            int tot=0;
            rep(j,0,m){
                int s=0;
                rep(k,0,i){
                    int x=(ll)C[j][k]*C[m-j][i-k]%P;
                    if (k&1) s=(s+P-x)%P;
                    else s=(s+x)%P;
                }
                tot=(tot+(ll)s*c[j])%P;
            }
            printf("%d ",(ll)tot*pw2(n-m)%P);
        }
    }
    return 0;
}