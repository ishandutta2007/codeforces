#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int hcf(int a,int b){
    if(b==0)return a;
    if(a==0)return b;
    return hcf(b%a,a);
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1],b[m+1];
    for(int i=0;i<=n;i++)cin>>a[i];
    for(int i=0;i<=m;i++)cin>>b[i];
    if(m>n)cout<<"0/1";
    else if(n>m){if((a[0]<0)^(b[0]<0))cout<<"-";cout<<"Infinity";}
    else{
        int k=hcf(abs(a[0]),abs(b[0]));
        a[0]/=k;b[0]/=k;
        if(b[0]<0)a[0]*=-1;
        cout<<a[0]<<"/"<<abs(b[0]);
    }
}