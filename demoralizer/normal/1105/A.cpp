#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
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

int k[105];
void solve(){
    int n;
    cin>>n;
    int a[n],sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=1;j<=100;j++){
            k[j]+=min(abs(a[i]-j),min(abs(a[i]-1-j),abs(a[i]+1-j)));
        }
    }
    int mi=k[1],t=1;
    for(int i=1;i<=100;i++){
        if(mi>k[i]){
            mi=k[i];
            t=i;
        }
    }
    cout<<t<<" "<<mi;
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