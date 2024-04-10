#include <bits/stdc++.h>
using namespace std;



int n,m;
int a[200005];
int b[200005];
vector<int> v[200005];
int x,y;
int cur;

inline int get_lower(int x) {
    int l=1;
    int r=n;
    x--;
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (b[mid]<=x) l=mid;
        else r=mid;
    }
    if (b[r]<=x) l=r;
    if (b[l]<=x) return l;
    return 0;
}

int main() {
//    freopen("input.in","r",stdin);
  //  freopen("output.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1;i<=n;++i) {
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    for (int i=1;i<=n;++i) {
        cur=get_lower(a[i]);
        for (int j=0;j<v[i].size();++j) {
            int to=v[i][j];
            if (a[to]<a[i]) --cur;
        }
        cout<<cur<<" ";
    }
}