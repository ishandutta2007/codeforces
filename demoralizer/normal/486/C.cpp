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

void solve(){
    int n,p,k=0,mn=-1,mx=-1;string s;
    cin>>n>>p>>s;vc<int> v;
    if(p<n/2)
    for(int i=0;i<n/2;i++){
        int a=abs(s[i]-s[n-1-i]);
        k+=min(a,26-a);
        if(a){
            mx=i;
            if(mn==-1)mn=i;
        }
    }
    else
    for(int i=n/2;i<n;i++){
        int a=abs(s[i]-s[n-1-i]);
        k+=min(a,26-a);
        if(a){
            mx=i;
            if(mn==-1)mn=i;
        }
    }
    p--;
    if(mn==-1)mx=mn=p;
    k+=min(abs(mn-p),abs(mx-p));
    k+=abs(mx-mn);
    cout<<k;
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