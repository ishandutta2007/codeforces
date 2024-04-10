#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;
const int maxk=10;

int n;
long long dp[maxn][maxk+2];
int c[maxn];
long long x[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    memset(dp,0xc0,sizeof(dp));
    dp[0][1]=0;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        vector<int> v[4];
        for(int j=1;j<=k;j++){
            cin>>c[j]>>x[j];
            v[c[j]].push_back(x[j]);
        }
        for(int j=1;j<=3;j++) sort(v[j].begin(),v[j].end(),greater<int>());
        vector<pair<int,int> > t,ct;
        for(int j=1;j<=3;j++){
            int ub=v[j].size();
            if(j==1)ub=min(ub,3);
            else ub=min(ub,1);
            for(int k=0;k<ub;k++) t.push_back(make_pair(j,v[j][k]));
        }
        for(int j=1;j<=maxk;j++) dp[i][j]=dp[i-1][j];
        int jc[6]={0,1,2,6,24,120};
        for(int x=0;x<(1<<t.size());x++){
            ct.clear();
            for(int j=0;j<t.size();j++) if((x>>j)&1)ct.push_back(t[j]);
            for(int zz=0;zz<jc[ct.size()];zz++){
                next_permutation(ct.begin(),ct.end());
                int tc=0;
                for(int j=0;j<ct.size();j++)tc+=ct[j].first;
                if(tc>3) continue;
                for(int j=1;j<=maxk;j++){
                    int cn=0;
                    long long dt=0;
                    for(int k=0;k<ct.size();k++){
                        if(j-cn==1){
                            dt+=(ct[k].second*2);
                        }else{
                            dt+=ct[k].second;
                        }
                        cn++;
                    }
                    dp[i][j]=max(dp[i][j],dp[i-1][(j-cn-1+maxk)%maxk+1]+dt);
                }
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=maxk;i++) ans=max(ans,dp[n][i]);
    cout<<ans;
    return 0;
}