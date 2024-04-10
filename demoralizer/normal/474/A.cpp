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
    char c;string s;char x[]="qwertyuiop",y[]="asdfghjkl;",z[]="zxcvbnm,./";
    cin>>c>>s;
    if(c=='L'){
        reverse(x,x+10);
        reverse(y,y+10);
        reverse(z,z+10);
    }
    for(int i=0;i<s.size();i++){
        if(find(x,x+10,s.at(i))!=x+10){
            cout<<*(find(x,x+10,s.at(i))-1);
        }
        if(find(y,y+10,s.at(i))!=y+10){
            cout<<*(find(y,y+10,s.at(i))-1);
        }
        if(find(z,z+10,s.at(i))!=z+10){
            cout<<*(find(z,z+10,s.at(i))-1);
        }
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