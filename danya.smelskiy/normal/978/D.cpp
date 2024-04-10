#include <bits/stdc++.h>
using namespace std;



int ans=1e9;

int n;
long long a[100005];


inline void check(int x,int y) {
    long long d=y-x;
    long long last=y;
    int res=0;
    if (x!=a[1]) ++res;
    if (y!=a[2]) ++res;
    for (int i=3;i<=n;++i) {
        if (abs(a[i]-(last+d))>1) return;
        if (a[i]!=last+d) ++res;
        last+=d;
    }
    ans=min(ans,res);
}

int main() {
//    freopen("input.in","r",stdin);
  //  freopen("output.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    if (n<=2) {
        cout<<0;
        return 0;
    }
    check(a[1],a[2]);
    check(a[1],a[2]+1);
    check(a[1],a[2]-1);
    check(a[1]+1,a[2]);
    check(a[1]+1,a[2]-1);
    check(a[1]+1,a[2]+1);
    check(a[1]-1,a[2]);
    check(a[1]-1,a[2]-1);
    check(a[1]-1,a[2]+1);
    if (ans==1e9) ans=-1;
    cout<<ans;
}