#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define msi map<string,int>
#define mii map<int,int>
#define psi pair<string,int>
#define pis pair<int,string>
#define piii pair<int,pii>
mii x;int rem[100009];ll dp[100009][2];
ll sol(mii::iterator i,int mr){
    if(i==x.end())return 0;
    ll a=-i->fr,b=i->sc;
    if(rem[a]){
        i++;
        return sol(i,0);
    }
    ll &ans=dp[a][mr];
    if(ans!=-1)return ans;
    if(mr){
        i++;
        rem[a-1]=1;rem[a]=1;
        ans=(a*b)+sol(i,0);
        rem[a-1]=0;rem[a]=0;
        return ans;
    }
    else{
        ans=sol(i,1);
        i++;
        if(-i->fr==a-1)
            ans=max(ans,sol(i,1));
        return ans;
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        x[-t]++;
    }
    memset(dp,-1,sizeof(dp));
    ll ans=sol(x.begin(),0);
    cout<<ans;
}