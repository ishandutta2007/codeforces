#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=5010,INF=1e9;
void tomin(int& x,int y){x=(x>y)?(y):(x);}
int n,K,p[MAXN],pos[MAXN];
int dp[2][9][1<<9];
int cnt[MAXN][MAXN];
int tmp[20],tot;
bool cmp(int x,int y){return pos[x]>pos[y];}
int main(){
    
    cin>>n>>K;
    rep(i,1,n)cin>>p[i],pos[p[i]]=i;
    rep(i,1,n)rep(j,1,n)cnt[i][j]=cnt[i-1][j]+(pos[i]>j);

    rep(i,0,1)rep(j,0,8)rep(k,0,511)dp[i][j][k]=INF;
    dp[0][0][1]=0;

    rep(i,0,n-1){
        rep(j,0,8)rep(k,0,511)dp[(i+1)&1][j][k]=INF;
        rep(j,0,K)rep(k,0,(1<<(K+1))-1){
            if(dp[i&1][j][k]==INF)continue;
            int minn=i-j;if(minn<0)continue;
            int cur=-1;
            rep(x,0,K)if(!(k>>x&1)){cur=x;break;}
            
            if(cur==-1)cur=K+1;
            int state=0;
            rep(x,cur+1,K)if(k>>x&1){state|=(1<<(x-cur));}
            int minv=i-j+cur;
            if(minv<(i+1-k) || minv>i+1)continue;
            tot=0;
            rep(x,0,K)if(minv+x <= n)tmp[++tot]=minv+x;
            sort(tmp+1,tmp+1+tot,cmp);
            int sum=0;
            rep(idx,1,tot){
                int x=tmp[idx]-minv;
                if(state>>x&1)sum++;
                else{
                    int rest=sum+cnt[minv-1][pos[minv+x]];

                    tomin(dp[(i+1)&1][(i+1)-minv][state|(1<<x)],dp[i&1][j][k]+rest);
                }
            }
        }
    }

    int ans=INF;
    rep(j,0,8)rep(k,0,511)tomin(ans,dp[n&1][j][k]);
    cout<<ans<<"\n";
    return 0;
}