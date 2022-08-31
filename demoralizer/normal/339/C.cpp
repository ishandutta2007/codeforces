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

vc<int> v,u;
int m;
int tryit(int diff,int t,int l){
    if(diff>10||diff<=0){
        return -1;
    }
    if(t==m){
        return -2;
    }
    for(int i=0;i<v.size();i++){
        if(i==l)continue;
        int k=tryit(v[i]-diff,t+1,i);
        if(k==-2){u.pb(v[i]);return -2;}
    }
   return 5;
}
void solve(){
    string s;
    cin>>s>>m;
    for(int i=0;i<10;i++){
        if(s[i]=='1')v.pb(i+1);
    }
    for(int i=0;i<v.size();i++){
        if(tryit(v[i],1,i)==-2){
            u.pb(v[i]);
            reverse(u.begin(),u.end());
            cout<<"YES\n";
            for(int i:u)cout<<i<<" ";
            return;
        }
    }

    cout<<"NO";
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