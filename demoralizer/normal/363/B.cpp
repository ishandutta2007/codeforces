#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
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
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int h[150005];
void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>h[i];
        h[i]+=h[i-1];
    }
    int z=h[n],x=1;
    for(int i=0;i<n-k+1;i++){
        if(z>h[i+k]-h[i])z=h[i+k]-h[i],x=i+1;
    }
    cout<<x;
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}