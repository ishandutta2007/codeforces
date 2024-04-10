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
    int k;string s;
    cin>>s>>k;
    int n=s.size(),q=0,a=0;
    for(char i:s)if(i=='?')q++;else if(i=='*')a++;
    if(k<n-2*a-2*q){cout<<"Impossible";return;}
    if(a==0&&k>(n-a-q)){cout<<"Impossible";return;}
    n-=a+q;
    int r=n-k;
    for(int i=0;i<s.size();i++){
        if(s[i+1]=='?'){
            if(r>0){
                r--;i++;continue;
            }
            else{
                cout<<s[i];
                i++;
                continue;
            }
        }
        else if(s[i+1]=='*'){
            if(r>0){
                r--;i++;continue;
            }
            else if(r==0){
                cout<<s[i];
                i++;
                continue;
            }
            else{
                r*=-1;
                r++;char c=s[i];
                while(r--){
                    cout<<c;
                }
                r=0;
                i++;
                continue;
            }
        }
        else{
            cout<<s[i];
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