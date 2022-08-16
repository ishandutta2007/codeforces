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

int ans[100005];
void solve(){
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int &i:a)cin>>i;
    set<int> s;
    for(int i=n-1;i>=0;i--){
        if(s.find(a[i])==s.end()){
            ans[i+1]=1;
            s.insert(a[i]);
        }
        ans[i+1]+=ans[i+2];
    }
    for(int i=0;i<m;i++){
        int t;cin>>t;
        cout<<ans[t]<<"\n";
    }
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