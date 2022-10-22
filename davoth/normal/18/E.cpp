#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10;
const int MOD=1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
/*ll pow(ll x, ll y, int mod){
    if(y==0) return 1;
    if(y==1) return x%mod;
    ll a=y/2,b=y/2;
    b+=y%2;
    return (pow(x,a,mod)*pow(x,b,mod))%mod;
}
ll gcd(ll a,ll b){
    if(a==b) return a;
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b,a%b);
    else return gcd(a,b%a);
}*/
int n,m;
pair<int,pair<int,int> > dp[501][26][26];
int main() {
    fast_io;
    cin >> n >> m;
    string a[n],b[n];
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++) dp[0][i][j]={0,{0,0}};
    }
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=1; i<=n; i++){
        for(int j=0; j<26; j++){
            for(int k=0; k<26; k++){
                dp[i][j][k]={1e9,{0,0}};
                if(j==k) continue;
                int diff=0;
                char A='a'+j,B='a'+k;
                for(int p=0; p<m; p++){
                    if((p%2==0 && a[i-1][p]!=A) || (p%2==1 && a[i-1][p]!=B)) diff++;
                }
                for(int p=0; p<26; p++){
                    for(int q=0; q<26; q++){
                        if(p==j || q==k || p==q) continue;
                        dp[i][j][k]=min(dp[i][j][k],{dp[i-1][p][q].F+diff,{p,q}});
                    }
                }
            }
        }
    }
    pair<int,pair<int,int> > ans={1e9,{100,100}};
    int aj=-1,ai=-1;
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            if(i==j) continue;
            if(ans>dp[n][i][j]) aj=j,ai=i,ans=dp[n][i][j];
        }
    }
    int fa=ans.F;
    cout << fa << '\n';
    for(int i=n; i>=1; i--){
        string s;
        for(int j=0; j<m; j++){
            if(j%2==0) s+='a'+ai;
            else s+='a'+aj;
        }
        b[i-1]=s;
        aj=ans.S.S;
        ai=ans.S.F;
        ans=dp[i-1][ai][aj];
    }

    for(int i=0; i<n; i++) cout << b[i] << '\n';
    //cout << dp[3][0][2].S.F << ' ' << dp[3][0][2].S.S;
    return 0;
}