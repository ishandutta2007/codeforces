#include <bits/stdc++.h>
using namespace std;




int n,m;
int x;
bool used[10005];
int clr[10005];
int p[100005];
int sz[10005];

int get(int x) {
    if (x==p[x]) return x;
    return p[x]=get(p[x]);
}

inline int get_g(int x) {
    if (used[x]) return clr[get(x)];
    sz[x]=1;
    clr[x]=x;
    used[x]=true;
    int l=x-1;
    while (l>=0 && !used[l] && sz[x]<m) {
        used[l]=true;
        p[l]=x;
        sz[x]++;
        clr[x]=l;
        --l;
    }
    if (l>=0 && used[l]) {
        int xx=get(l);
        if (sz[xx]+sz[x]<=m) {
            p[x]=xx;
            sz[xx]+=sz[x];
        }
    }
    return clr[get(x)];

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<=256;++i)
        p[i]=i;
    for (int i=1;i<=n;++i) {
        cin>>x;
        cout<<get_g(x)<<" ";
    }
}