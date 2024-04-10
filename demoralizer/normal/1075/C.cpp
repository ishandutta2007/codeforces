#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
int d[100005];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,t,p,q;
    cin>>n>>m;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    a[n]=1000000000;
    int b[m];
    for(int i=0;i<m;i++){
        cin>>p>>q>>t;
        if(p>1)b[i]=0;
        else b[i]=q;
    }
    sort(b,b+m);
    t=0;
    for(int i=0;i<=n&&t<m;i++){
        while(b[t]<a[i]&&t<m){d[i]++;t++;}
    }
    for(int i=1;i<=n;i++)d[i]+=d[i-1];
    for(int i=0;i<=n;i++)d[i]=m-d[i]+i;
    t=d[0];
    for(int i=0;i<=n;i++)
        if(d[i]<t)t=d[i];
    cout<<t;
}