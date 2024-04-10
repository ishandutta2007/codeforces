#include <bits/stdc++.h>
using namespace std;

long long n,k,m,x,y;
long long a[200005];
long long q[200005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>m;
    for (long long i=1;i<=n;++i) {
        cin>>x>>y;
        if (x>y) swap(x,y);
        a[x]++;
        a[y+1]--;
    }
    long long last=0;
    for (long long i=1;i<=200000;++i){
        last+=a[i];
        q[i]=q[i-1];
        if (last>=k) ++q[i];
    }
    for (long long i=1;i<=m;++i){
        cin>>x>>y;
        if (x>y) swap(x,y);
        long long res=q[y]-q[x-1];
        cout<<res<<'\n';
    }
}