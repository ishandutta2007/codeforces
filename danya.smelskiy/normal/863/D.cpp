#include <bits/stdc++.h>
using namespace std;

int n,q,m;
int a[200005];
int t[200005];
int l[200005];
int r[200005];
int x;


inline int solve(int x){
    for (int i=q;i>0;--i) {
        if (t[i]==1 && l[i]<=x && r[i]>=x) {
            if (x==l[i]) x=r[i];
            else --x;
        } else if (l[i]<=x && r[i]>=x) {
            int ll=x-l[i];
            x=r[i]-ll;
        }
    }
    return a[x];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=q;++i) {
        cin>>t[i]>>l[i]>>r[i];
    }
    for (int i=1;i<=m;++i) {
        cin>>x;
        cout<<solve(x)<<" ";
    }
}