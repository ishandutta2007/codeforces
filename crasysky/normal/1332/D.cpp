#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define sit set<int>::iterator
#define pb push_back
#define ll long long
using namespace std;
const int N=5e5+5;
int U=(1<<18)-1;
signed main(){
    int k; cin>>k;
    cout<<2<<" "<<3<<endl;
    cout<<U<<" "<<k<<" "<<0<<endl;
    cout<<(U^k)<<" "<<U<<" "<<k<<endl;
    return 0;
}