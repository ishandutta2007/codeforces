#include <bits/stdc++.h>
using namespace std;

int n,m;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    int res=0;
    res=((n+2)/3)*m;
    res=max(res,((m+2)/3)*n);
    res=max(res,(n*m+1)/2);
    if (n>m) swap(n,m);
    if (n==2) {
        int cur=(m/4)*4;
        cur+=min((m%4)*2,4);
        res=max(res,cur);
    }
    cout<<res;
}