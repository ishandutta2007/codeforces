#include <bits/stdc++.h>
using namespace std;




int n,m,k;
long long ans;
int x,y;
int p[100005];
int pos[100005];

inline int solve(int x) {
    int res=(pos[x]+k-1)/k;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i) {
        cin>>x;
        pos[x]=i;
        p[i]=x;
    }
    long long ans=0;
    while (m--) {
        cin>>x;
        ans+=solve(x);
        y=pos[x];
        if (y>1) {
            swap(p[y],p[y-1]);
            swap(pos[p[y]],pos[p[y-1]]);
        }
    }
    cout<<ans;
}