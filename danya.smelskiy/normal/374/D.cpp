#include <bits/stdc++.h>
using namespace std;


int n,m;
int a[1000005];
int b[1000005];
int t[4000005];
int sz;

inline void update(int x,int y){
    x+=sz-1;
    t[x]=y;
    x>>=1;
    while (x) {
        t[x]=t[x+x]+t[x+x+1];
        x>>=1;
    }
}
int kth(int l,int r,int x,int y){
    if (l==r) return l;
    int mid=(l+r)>>1;
    if (t[x+x]>=y) return kth(l,mid,x+x,y);
    else return kth(mid+1,r,x+x+1,y-t[x+x]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        cin>>a[i];
    }
    a[++m]=1e9;
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=n;++i) {
        int x;
        cin>>x;
        if (x==-1) {
            int j=1;
            while (a[j]<=t[1]) ++j;
            --j;
            while (j) {
                int pos=kth(1,sz,1,a[j]);
                update(pos,0);
                --j;
            }
            continue;
        }
        b[i]=x;
        update(i,1);
    }
    if (!t[1]) {
        cout<<"Poor stack!";
        return 0;
    }
    for (int i=1;i<=t[1];++i) {
        int pos=kth(1,sz,1,i);
        cout<<b[pos];
    }
}