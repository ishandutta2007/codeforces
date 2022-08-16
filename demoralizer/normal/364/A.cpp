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

int z[4004];
set<int> fact;
mii m;
void solve(){
    int n;string s;
    cin>>n>>s;
    for (int i = 0; i < s.size(); ++i)
    {
        z[i+1]=s[i]-'0';
        z[i+1]+=z[i];
    }
    if(n)
    for (int i = 1; i*i <= n; ++i)
    {
        if(n%i==0){fact.insert(i);fact.insert(n/i);}
    }
    else fact.insert(0);
    for (int i = 1; i <= s.size(); ++i)
    {
        for (int j = i; j <= s.size(); ++j)
        {
            int sum=z[j]-z[i-1];
            if(fact.find(sum)!=fact.end())m[sum]++;
        }
    }
    int ans=0;
    if(n)
    for(auto z:m){
        int a=z.fr,b=z.sc;
        if(a*a==n){
            ans+=b*b;
        }
        else{
            ans+=b*m[n/a];
        }
    }
    else{
        ans=(s.size()*(1+s.size())-m[0])*m[0];
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