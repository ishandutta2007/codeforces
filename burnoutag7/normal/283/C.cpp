#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,q,t;
int a[305];
int to[305];
bool rt[305];
bool u[305];
vector<int> v;
int dp[305][100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(to,-1,sizeof(to));
    memset(rt,1,sizeof(rt));

    cin>>n>>q>>t;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<q;i++){
        int aa,bb;
        cin>>aa>>bb;aa--;bb--;
        to[aa]=bb;
        rt[bb]=0;
    }
    ll tmp=0ll;
    for(int i=0;i<n;i++){
        if(!rt[i])continue;
        int sum=0;
        int cur=i;
        while(true){
            u[cur]=1;
            sum+=a[cur];
            v.push_back(sum);
            if(to[cur]==-1)break;
            tmp+=sum;
            cur=to[cur];
        }
    }

    for(int i=0;i<n;i++){
        if(u[i])continue;
        cout<<0<<endl;
        return 0;
    }
    if(tmp>t){
        cout<<0<<endl;
        return 0;
    }

    t-=tmp;
    int m=v.size();
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<=t;j++){
            dp[i+1][j]=dp[i][j];
            if(j>=v[i]){
                dp[i+1][j]+=dp[i+1][j-v[i]];
                if(dp[i+1][j]>=1000000007)dp[i+1][j]-=1000000007;
            }
        }
    }
    cout<<dp[m][t]<<endl;

    return 0;
}