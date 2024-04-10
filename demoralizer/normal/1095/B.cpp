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
    int n;
    cin>>n;
    int a[n+5];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int x=a[n-1]-a[0],y=a[n-1]-a[1],z=a[n-2]-a[0],p=min(x,y);
    p=min(p,z);cout<<p;
}