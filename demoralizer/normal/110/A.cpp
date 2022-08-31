#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define msi map<string,int>
#define mii map<int,int>
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,m,c=0;
    cin>>n;
    m=n;
    while(m>0){
        if(m%10==4||m%10==7)c++;
        m/=10;
    }
    if(c==0)goto no;
    while(c>0){
        if(c%10!=4&&c%10!=7){no: cout<<"NO";return 0;}
        c/=10;
    }
    cout<<"YES";
}