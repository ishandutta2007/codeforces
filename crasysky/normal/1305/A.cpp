#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define sit set<int>::iterator
#define ll long long
using namespace std;
const int N=1e3+3,INF=1e9;
int a[N],b[N];
int main(){
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        rep(i,1,n) cin>>a[i];
        rep(i,1,n) cin>>b[i];
        sort(a+1,a+1+n),sort(b+1,b+1+n);
        rep(i,1,n) cout<<a[i]<<" ";
        cout<<endl;
        rep(i,1,n) cout<<b[i]<<" ";
        cout<<endl;
    }
}