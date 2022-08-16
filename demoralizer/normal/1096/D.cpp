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
ll n;
char c[100009];
ll a[100009];
ll dp[100009][4];
ll cal(int p,int m){
    if(p==n)return 0;
    ll &ans=dp[p][m],t=-1;
    if(ans!=-1)return ans;
    ans=a[p]+cal(p+1,m);
    if((m==0&&c[p]=='h')||(m==1&&c[p]=='a')||(m==2&&c[p]=='r')){
        t=cal(p+1,m+1);
    }
    else if(m==3&&c[p]=='d');
    else{
        t=cal(p+1,m);
    }
    if(t!=-1)ans=min(ans,t);
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n;
    cin>>c;
    for(int i=0;i<n;i++)cin>>a[i];
    memset(dp,-1,sizeof(dp));
    ll ans=cal(0,0);
    cout<<ans;
}