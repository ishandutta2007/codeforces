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
    string s;
    cin>>s;
    int n=s.size();
    int k=0,t=0;
    vc<int> o,clo;
    for(int i=0;i<n;i++){
        if(s[i]=='[')o.pb(i);
        if(s[i]==']')clo.pb(i);
    }
    int a,b,c,d,e,f,g,h;
    if(o.size()==0||clo.size()==0)goto no;
    a=o[0];d=clo[clo.size()-1];
    if(a>d)goto no;
    b=-1;c=-1;
    for(int i=a;i<d;i++){
        if(s[i]==':'){
            if(b==-1)b=i;
            else c=i;
        }
    }
    if(c==-1)goto no;
    h=0;
    for(int i=b;i<c;i++){
        if(s[i]=='|')h++;
    }
    h+=4;
    cout<<h;
    return;
    no:
        cout<<-1;
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