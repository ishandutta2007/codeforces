#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=3003,P=998244353;
void upd(int &x,int y){ x+=y; x-=x>=P?P:0; }
namespace subtask1{
    int dp[N][N];
    void main(int n){
        dp[0][1]=1;
        rep(i,0,n)
            rep(j,1,n){
                upd(dp[i][j+1],dp[i][j]);
                if (i+j<=n) upd(dp[i+j][j],dp[i][j]);
            }
        int ans=0; rep(i,1,n) upd(ans,dp[i][n]);
        cout<<ans<<endl;
    }
}
namespace subtask2{
    vector<int> dp[N][N];
    void main(int n){
        rep(i,1,n) rep(j,1,i) dp[i][j].resize(i/j+1);
        dp[0][0].resize(n+1); dp[0][0][n]=1;
        rep(i,0,n)
            rep(j,i==0?0:1,i)
                per(k,j==0?n:i/j,1){
                    upd(dp[i][j][k-1],dp[i][j][k]);
                    if (i+(j+1)*k<=n)
                        upd(dp[i+(j+1)*k][j+1][k],dp[i][j][k]);
                }
        int ans=0;
        rep(i,1,n) rep(j,1,i) upd(ans,dp[i][j][0]);
        cout<<ans<<endl;
    }
}
namespace subtask3{
    int a[N],ans=0,n,k,b[N],c[N];
    bool check(int t){
        rep(i,1,t) b[i]=a[t-i+1];
        rep(cas,1,k){
            int t2=0;
            rep(i,1,t){
                if (t2+b[i]>n) return false;
                rep(j,1,b[i]) c[++t2]=i;
            }
            rep(i,1,t2) b[t2-i+1]=c[i]; t=t2;
        }
        return true;
    }
    void solve(int step){
        if (step&&!check(step)) return;
        ++ans;
        ++step,a[step]=a[step-1]; solve(step);
        if (--step) ++a[step],solve(step);
    }
    void main(int n2,int k2){
        if (k2>=20){ cout<<1<<endl; return; }
        n=n2,k=k2; a[0]=1; solve(0);
        cout<<ans-1<<endl;
    }
}
int main(){
    int n,k; cin>>n>>k;
    if (k==1) subtask1::main(n);
    else if (k==2) subtask2::main(n);
    else subtask3::main(n,k);
    return 0;
}