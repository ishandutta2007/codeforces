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

int primes[10000005];
vc<int> v;
void seive(){
    primes[1]=1;
    for(int i=2;i<10000003;i++){
        if(primes[i])continue;
        for(int j=i*i;j<10000003;j+=i){
            primes[j]=1;
        }
    }
    for(int i=1;i<10000003;i++)primes[i]^=1;
}
void solve(){
    seive();
    int n;
    cin>>n;
    if(n==1){
        cout<<"1\n0";
        return;
    }
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            n/=i;if(n==1)break;
            v.pb(i);
            if(v.size()==2){
                cout<<"1\n"<<v[0]*v[1];
                return;
            }
        }
    }
    if(v.empty()){
        cout<<"1\n0";
        return;
    }
    cout<<2;
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