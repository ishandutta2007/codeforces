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
    int n,a=0,b=0,c=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(t==25){
            a++;
        }
        else if(t==50){
            b++;
            if(a==0)goto no;
            a--;
        }
        else{
            c++;
            if(a==0)goto no;
            a--;
            if(b)b--;
            else if(a>1)a-=2;
            else goto no;
        }
    }
    cout<<"YES";return;
    no:;cout<<"NO";
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