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
int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return ((a*t*t)%p);
    else return ((t*t)%p);
}

void solve(){
    int n;
    cin>>n;
    int m=n;
    vc<int> yo;
    while(m!=0){
        yo.pb(m%10);
        m/=10;
    }
    int i;
    for(i=yo.size()-1;i>=0;i--){
        if(yo[i]>1)break;
    }
    for(;i>=0;i--){
        yo[i]=1;
    }
    int p=1,ans=0;
    for(int i=0;i<yo.size();i++){
        ans+=p*yo[i];
        p*=2;
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