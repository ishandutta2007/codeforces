#include <bits/stdc++.h>
using namespace std;


int n;
long long w;
long long last;
long long mn=0;
long long mx=0;
long long a[1005];


int main() {
//    freopen("input.in","r",stdin);
  //  freopen("output.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>w;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        last+=a[i];
        mn=min(mn,last);
        mx=max(mx,last);
    }
    mn=abs(mn);
    long long x=mn;
    long long y=w-mx;
    if (x<=y) cout<<y-x+1ll;
    else cout<<0;
}