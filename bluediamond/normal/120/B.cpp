#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1001;

int n,p,v[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    cin>>n>>p;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }
    while(v[p]==0) {
        p++;
        if(p>n)
            p=1;
    }
    cout<<p<<"\n";
    return 0;
}
/**
**/