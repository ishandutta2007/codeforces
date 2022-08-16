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

void solve(){
    int n;
    string s;
    cin>>n>>s;
    char z[]={'R','G','B'};
    map<char,int> m;
    m['R']=0;m['G']=1;m['B']=2;int c=0;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            int t=(m[s[i]]+1)%3;
            if(i<n-1)if(z[t]==s[i+1])t=(t+1)%3;
            s[i]=z[t];c++;
        }
    }
    cout<<c<<"\n"<<s;
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