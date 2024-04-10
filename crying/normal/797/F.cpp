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
const ll MAXN=5010,INF=1e18;
ll n,m,a[MAXN];
array<ll,2>b[MAXN];
ll dp[2][MAXN],ans=INF;
ll cost[MAXN];
int q[MAXN],head,rear;
void calc(int i){
    //i
    rep(j,1,n)cost[j]=cost[j-1]+abs(a[j]-b[i][0]);
}
void dp_init(int i){
    rep(j,0,5005)dp[i&1][j]=INF;
}
int main(){
    //freopen("jandt.in","r",stdin);
    //freopen("jandt.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,n)cin>>a[i];sort(a+1,a+1+n);
    ll sum=0;
    rep(i,1,m){
        cin>>b[i][0]>>b[i][1];
        sum+=b[i][1];
    }
    if(sum<n){cout<<"-1\n";return 0;}
    sort(b+1,b+1+m);
    
    //dp
    //
    calc(1);
    dp_init(1);
    dp[1][0]=0;
    rep(i,1,n)if(i<=b[1][1])dp[1][i]=cost[i];
    //
    rep(j,2,m){
        calc(j);
        dp_init(j);
        //
        dp[j&1][0]=0;
        head=rear=1;
        q[rear++]=0;
        rep(i,1,n){
            while(head<rear && i-q[head]>b[j][1])head++;
            while(head<rear && dp[(j-1)&1][q[rear-1]]-cost[q[rear-1]] >= dp[(j-1)&1][i]-cost[i])rear--;
            q[rear++]=i;
            int k=q[head];
            dp[j&1][i]=dp[(j-1)&1][k]+cost[i]-cost[k];
        }
    }   
    ans=dp[m&1][n];

    cout<<ans<<"\n";
    return 0;
}