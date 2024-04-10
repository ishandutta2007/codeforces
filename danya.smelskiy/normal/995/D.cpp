#include <bits/stdc++.h>
using namespace std;



int n,m;
int a[(1<<18)];
long double s;
int x,xx;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    long double y=(1<<n);
    for (int i=0;i<(1<<n);++i) {
        cin>>a[i];
        s+=a[i];
    }
    cout<<fixed<<setprecision(7);
    cout<<s/y<<'\n';
    for (int i=1;i<=m;++i) {
        cin>>x>>xx;
        s-=a[x];
        a[x]=xx;
        s+=xx;
        cout<<s/y<<'\n';
    }
}