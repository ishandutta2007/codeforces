#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;
const long long mdn=998244353;

int n,m;
int a[2][maxn],x[2];
long long dp[maxn][3];

long long pwr(long long bse,int ex){
    long long ans=1;
    while(ex--) ans=(ans*bse)%mdn;
    return ans;
}
long long calc(int l,int r,int t){
    if(l==1&&r==x[t]){
        return (pwr(m-1,r-l)*m)%mdn;
    }else if(l==1||r==x[t]){
        return pwr(m-1,r-l+1);
    }
    if(a[t][l-1]==a[t][r+1]){
        dp[l-1][0]=1;dp[l-1][1]=0;
        for(int i=l;i<=r+1;i++){
            dp[i][0]=dp[i-1][1];
            dp[i][1]=(dp[i-1][0]*(m-1)+dp[i-1][1]*(m-2))%mdn;
        }
        return dp[r+1][0];
    }else{
        if(m>=3){
            dp[l-1][0]=1;dp[l-1][1]=0;dp[l-1][2]=0;
            for(int i=l;i<=r+1;i++){
                dp[i][0]=(dp[i-1][1]+dp[i-1][2])%mdn;
                dp[i][1]=(dp[i-1][0]+dp[i-1][2])%mdn;
                dp[i][2]=(dp[i-1][0]*(m-2)+dp[i-1][1]*(m-2)+dp[i-1][2]*(m-3))%mdn;
            }
            return dp[r+1][1];
        }else{
            return (r-l)&1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        if(i&1){
            cin>>a[0][++x[0]];
        }else{
            cin>>a[1][++x[1]];
        }
    }
    long long ans=1;
    for(int t=0;t<2;t++){
        vector<pair<int,int> > v;
        int lp=-1;
        for(int i=1;i<=x[t];i++){
            if(a[t][i]!=-1){
                if(a[t][i-1]==a[t][i]||a[t][i+1]==a[t][i]){
                    cout<<0;
                    return 0;
                }
            }
        }
        for(int i=1;i<=x[t]+1;i++){
            if(i>x[t]||a[t][i]!=-1){
                if(lp!=-1){
                    v.push_back(make_pair(lp,i-1));
                    lp=-1;
                }
            }else if(a[t][i]==-1&&lp==-1){
                lp=i;
            }
        }
        for(int i=0;i<v.size();i++){
            ans=(ans*calc(v[i].first,v[i].second,t))%mdn;
        }
    }
    cout<<ans;
    return 0;
}//qwq