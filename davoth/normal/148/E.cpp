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
ll pow(ll x, ll y, int mod){
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
}
ll n,m;
int main() {
    fast_io;
    cin >> n >> m;
    int s[n][101],dp[n][m+1],dd[n][m+1];
    vector<int> a[n];
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        int y;
        cin >> y;
        a[i].push_back(y);
        s[i][0]=y;
        for(int j=1; j<x; j++){
            cin >> y;
            a[i].push_back(y);
            s[i][j]=s[i][j-1]+a[i][j];
        }
    }
    for(int i=0; i<n; i++) for(int j=0; j<=m; j++) dp[i][j]=0;
    for(int i=0; i<=m; i++){
        for(int j=0; j<n; j++){
            if(i>=a[j].size()) dp[j][i]=s[j][a[j].size()-1];
            else{
                int mx=0;
                for(int k=0; k<i; k++){
                    if(s[j][k]+s[j][a[j].size()-1]-s[j][a[j].size()-i+k]>mx) mx=s[j][k]+s[j][a[j].size()-1]-s[j][a[j].size()-i+k];
                }
                if(s[j][a[j].size()-1]-s[j][a[j].size()-i-1]>mx) mx=s[j][a[j].size()-1]-s[j][a[j].size()-i-1];
                dp[j][i]=mx;
            }
        }
    }
    for(int i=0; i<n; i++) for(int j=0; j<=m; j++) dd[i][j]=0;
    for(int i=0; i<n; i++) dd[i][0]=0;
    for(int i=0; i<m; i++){
        dd[0][i+1]=dp[0][i+1];
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<=m; j++){
            int mx=0;
            for(int k=0; k<=min((int)a[i].size(),j); k++){
                mx=max(mx,dd[i-1][j-k]+dp[i][k]);
            }
            dd[i][j]=mx;
        }
    }
    cout << dd[n-1][m];
    /*for(int i=0; i<n; i++){
        for(int j=0; j<=m; j++) cout << i << ' ' << j << ' ' << dd[i][j] << '\n';
    }*/
    return 0;
}