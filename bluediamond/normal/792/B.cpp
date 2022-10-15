#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100+5;
int n,k,p=1;
bool viz[N];

inline int nxt(int x) {
    if(x==n) {
        return 1;
    }
    return x+1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=k;i++) {
        int x;
        cin>>x;
        x%=(n+1-i);
        for(int j=1;j<=x;j++) {
            p=nxt(p);
            while(viz[p]==1) {
                p=nxt(p);
            }
        }
        cout<<p<<" ";
        viz[p]=1;
        while(viz[p]==1) {
            p=nxt(p);
        }
    }
    cout<<"\n";
    return 0;
}