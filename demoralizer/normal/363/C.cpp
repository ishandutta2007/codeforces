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
    string s,a,b;
    cin>>s;
    int n=s.size();a+=s[0];a+=s[1];int j=2,k=3;
    if(n<=2){cout<<s;return;}
    for(int i=2;i<n;i++){
        if(s[i]==a[j-1]&&s[i]==a[j-2])continue;
        j++;
        a+=s[i];
    }
    if(j<=3){cout<<a;return;}
    b+=a[0];b+=a[1];b+=a[2];
    for(int i=3;i<j;i++){
        if(a[i]==b[k-1]&&b[k-2]==b[k-3])continue;
        k++;
        b+=a[i];
    }
    cout<<b;
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