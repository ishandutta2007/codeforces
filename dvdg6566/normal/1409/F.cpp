#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define lb lower_bound
const int MAXN=201;

int dp[MAXN][MAXN][MAXN];

string A,B;
int N,K;

int ask(int n,int k,int ap){
    if(k<0)return -1e9;
    if(n==N)return 0;
    if(dp[n][k][ap]!=-1)return dp[n][k][ap];
    
    if(B[0] == B[1]){
        if(A[n] == B[0]){
            return dp[n][k][ap]=ap+ask(n+1,k,ap+1);
        }else{
            int ans=max(ap+ask(n+1,k-1,ap+1), ask(n+1,k,ap));
            return dp[n][k][ap]=ans;
        }
    }
    int ans=0;

    if(A[n] == B[0]){
        ans=max(ans,ask(n+1,k,ap+1));
    }
    if(A[n] == B[1]){
        ans=max(ans,ap+ask(n+1,k,ap));
    }
    ans=max(ans, ask(n+1,k,ap));
    //changing

    ans=max(ans,ap+ask(n+1,k-1,ap));
    ans=max(ans,ask(n+1,k-1,ap+1));
    // cerr<<n<<' '<<k<<' '<<ap<<' '<<ans<<'\n';
    return dp[n][k][ap]=ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>K>>A>>B;
    memset(dp,-1,sizeof(dp));
    cout<<ask(0,K,0);
}