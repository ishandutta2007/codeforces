#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int a[10005];
long long s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=m;++i) {
        cin>>a[i];
        s+=a[i];
    }
    if (s<n) cout<<"-1";
    else if (a[k]==1) cout<<0;
    else if (s-a[k]<n-1) cout<<1;
    else {
        long double res=1;
        --n;
        --a[k];
        --s;
        for (int i=s-n+1;i<=s;++i)
            res=(res/(long double)i);
        for (int i=s-n-a[k]+1;i<=s-a[k];++i)
            res=(res*(long double)i);
        cout<<1-res;
    }
}