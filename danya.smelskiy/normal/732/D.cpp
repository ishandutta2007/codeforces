#include <bits/stdc++.h>
using namespace std;


int n,m;
int d[100005];
int a[100005];
bool used[100005];
inline bool f(int mid) {
    memset(used,false,sizeof(used));
    int res=0;
    int kol=0;
    used[0]=true;
    for (int i=mid;i>0;--i) {
        if (used[d[i]]) res=max(res-1,0);
        else {
            ++kol;
            res+=a[d[i]];
            used[d[i]]=true;
        }
    }
    if (kol!=m) return false;
    return res<=0;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>d[i];
    for (int i=1;i<=m;++i)
        cin>>a[i];
    int l=1;
    int r=n;
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (f(mid)) r=mid;
        else l=mid;
    }
    if (f(l)) r=l;
    if (f(r)) cout<<r;
    else cout<<"-1";
}