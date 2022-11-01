#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1000000007;

string s;
int n;
int mch[705];
ll dp[705][705][3][3];
stack<int> st;
bool good[3][3],bad[3][3];

ll dfs(int l,int r,int cl,int cr){
    if(dp[l][r][cl][cr]!=-1)return dp[l][r][cl][cr];
    if(mch[l]==r){
        if(!good[cl][cr])return dp[l][r][cl][cr]=0;
        if(l+1==r)return dp[l][r][cl][cr]=(bad[cl][cr]?0:1);
        ll ans=0;
        for(int i=0;i<3;i++){
            if(!bad[cl][i]){
                for(int j=0;j<3;j++){
                    if(!bad[j][cr]){
                        ans=(ans+dfs(l+1,r-1,i,j))%mod;
                    }
                }
            }
        }
        return dp[l][r][cl][cr]=ans;
    }else{
        int m=mch[l];
        ll ans=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(!bad[i][j]){
                    ans=(ans+dfs(l,m,cl,i)*dfs(m+1,r,j,cr))%mod;
                }
            }
        }
        return dp[l][r][cl][cr]=ans;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push(i);
        }else{
            mch[st.top()]=i;
            mch[i]=st.top();
            st.pop();
        }
    }
    good[0][1]=good[0][2]=good[1][0]=good[2][0]=true;
    bad[1][1]=bad[2][2]=true;
    memset(dp,-1,sizeof(dp));
    ll ans=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ans=(ans+dfs(0,n-1,i,j))%mod;
        }
    }
    cout<<ans<<endl;

    return 0;
}