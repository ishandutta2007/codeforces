#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)                   (x).begin(),(x).end()
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
    if(b%2)return (((a*t)%p)*t)%p;
    else return ((t*t)%p);
}


void solve(){
    int n;
    cin>>n;
    if(n==1)cout<<"1";
    if(n==2)cout<<"2";
    if(n==3)cout<<"6";
    if(n==4)cout<<"12";
    if(n>4){
        if(n%2)cout<<(n*(n-1)*(n-2));
        else cout<<max(((n-3)*(n-1)*(n-2)),(n*(n-1)*(n-3))/gcd(n,n-3));
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