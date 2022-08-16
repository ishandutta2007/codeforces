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
#define psi pair<string,int>
#define pis pair<int,string>
#define piii pair<int,pii>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}


int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    int a[n+2],b[n+2],c[n+2];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n-1;i++)cin>>b[i];
    for(int i=0;i<n-2;i++)cin>>c[i];
    sort(a,a+n);sort(b,b+n-1);sort(c,c+n-2);
    for(int i=0;i<n;i++){
        if((i==n-1)||(a[i]!=b[i])){cout<<a[i];break;}
    }
    cout<<" ";
    for(int i=0;i<n-1;i++){
        if((i==n-2)||(b[i]!=c[i])){cout<<b[i];break;}
    }
}