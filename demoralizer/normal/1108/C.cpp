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
    string p[]={"RGB","RBG","GRB","GBR","BRG","BGR"};
    int n;
    cin>>n;
    string s;
    cin>>s;int ans,sr=0;
    for(int j=0;j<6;j++){
        int c=0;
        for(int i=0;i<n;i++){
            int k=i%3;
            if(p[j][k]!=s[i])c++;
        }
        if(j==0)ans=c;
        if(c<ans){
            sr=j;
            ans=c;
        }
    }
    cout<<ans<<"\n";
    for(int i=0;i<n;i++){
        int k=i%3;
        cout<<p[sr][k];
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