#include <bits/stdc++.h>
using namespace std;
int n,m,x,y;
long long dp[30001000];
long long dp2[30000100];
int lp[10004005];
vector<int> pr;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        ++dp[x];
    }
    for (int i=2;i<=(1e7);++i){
        if (lp[i]==0) {
            lp[i]=i;
           pr.push_back(i);
        }
        for (int j=0;j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=(1e7);++j) {
            lp[i*pr[j]]=pr[j];
        }
    }
    for (int i=(1e7);i>1;--i){
        if (lp[i]==i) { dp2[lp[i]]+=dp[i]; continue; }
        int x=i;
        dp2[lp[i]]+=dp[i];
        while (x%lp[i]==0) x/=lp[i];
        dp[x]+=dp[i];
    }
    for (int i=2;i<=(30000000);++i)
        dp2[i]+=dp2[i-1];
    cin>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        if (x>30000000) {
            cout<<"0"<<'\n';
            continue;
        }
        y=min(y,(int)30000000);
        cout<<dp2[y]-dp2[x-1]<<'\n';
    }
}