#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<ll,ll>
#define msi map<string,ll>
#define mii map<ll,ll>
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,t,a=0,b=0,c=0,d=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        if(t==1)a++;
        else if(t==2)b++;
        else if(t==3)c++;
        else d++;
    }
    d+=c+(b+1)/2;
    if(b%2)a-=2;
    a-=c;
    if(a>0){
        d+=a/4+(a%4!=0);
    }
    cout<<d;
}