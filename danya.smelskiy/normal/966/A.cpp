#include <bits/stdc++.h>
using namespace std;


int ce,cl;
int n;
int m;
int a[100005];
int b[100005];
int v;

inline pair<int,int> get2(int x) {
    int l=1;
    int r=ce;
    if (!r) return make_pair(0,0);
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (b[mid]<=x) l=mid;
        else r=mid;
    }
    if (b[r]<=x) l=r;
    pair<int,int> res=make_pair(0,0);
    if (b[l]<=x) res.first=b[l];
    while (l<=ce && b[l]<=x) ++l;
    if (l<=ce && b[l]>=x) res.second=b[l];
    return res;
}


inline pair<int,int> get1(int x) {
    int l=1;
    int r=cl;
    if (!r) return make_pair(0,0);
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (a[mid]<=x) l=mid;
        else r=mid;
    }
    if (a[r]<=x) l=r;
    pair<int,int> res=make_pair(0,0);
    if (a[l]<=x) res.first=a[l];
    while (l<=cl && a[l]<=x) ++l;
    if (l<=cl && a[l]>=x) res.second=a[l];
    return res;
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>cl>>ce>>v;
    for (int i=1;i<=cl;++i)
        cin>>a[i];
    for (int i=1;i<=ce;++i) {
        cin>>b[i];
    }
    int q;
    int x,y,xx,yy;
    cin>>q;
    while (q--) {
        cin>>x>>y>>xx>>yy;
        if (x==xx) {
            cout<<abs(y-yy)<<'\n';
            continue;
        }
        pair<int,int> z=get1(y);
        int res=2e9;
        if (z.first) {
            res=min(res,abs(x-xx)+y-z.first+abs(z.first-yy));
        }
        if (z.second) {
            res=min(res,abs(x-xx)+z.second-y+abs(z.second-yy));
        }
        z=get2(y);
        if (z.first) {
            res=min(res,(abs(x-xx)+v-1)/v+y-z.first+abs(z.first-yy));
        }
        if (z.second) {
            res=min(res,(abs(x-xx)+v-1)/v+z.second-y+abs(z.second-yy));
        }
        cout<<res<<'\n';
    }

}