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

int x[1000009],k[1000009];
void solve(){
    string s;
    int a,b,f=0,z=0,y=1;
    cin>>s>>a>>b;
    vc<int> v;
    for(int i=0;i<s.size();i++){
        z=10*z+s[i]-'0';
        z%=a;
        if((z==0)&&(i<s.size()-1))v.pb(i+1);
        if(i==0)
            x[s.size()-1]=1;
        else
            x[s.size()-1-i]=(10*x[s.size()-i])%b;
    }
    for(int i=s.size()-1;i>=0;i--){
        k[i]=((s[i]-'0')*x[i]+k[i+1])%b;
    }
    for(int i=0;i<v.size();i++){
        if((k[v[i]]==0)&&(s[v[i]]!='0')){
            f=v[i];break;
        }
    }
    if(f){
        cout<<"YES\n";
        cout<<s.substr(0,f);
        cout<<"\n"<<s.substr(f);
    }
    else cout<<"NO";
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