#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
#define piii              pair<int,pii>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}


void solve(){
    int n,m;
    cin>>n>>m;
    set<int> s[m];
    string a;
    for(int i=0;i<n;i++){
        cin>>a;
        for(int j=0;j<m;j++){
            s[j].insert(a[j]);
        }
    }
    int ans=1;
    for(int i=0;i<m;i++){
        ans=(ans*s[i].size())%M;
    }
    cout<<ans;
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