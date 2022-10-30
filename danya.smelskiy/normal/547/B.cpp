#include <bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
int n;
int a[300005];
int l[300005];
int r[300005];
int x;
int p[300005];
pair<int,int> q[300005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    int sz=0;
    q[sz]=make_pair(-inf,0);
    for (int i=1;i<=n;++i) {
        x=a[i];
        while (x<=q[sz].first) --sz;
        l[i]=q[sz].second;
        ++sz;
        q[sz]=make_pair(x,i);
    }
    sz=0;
    q[sz]=make_pair(-inf,n+1);
    for (int i=n;i>0;--i){
        x=a[i];
        while (x<=q[sz].first) --sz;
        r[i]=q[sz].second;
        ++sz;
        q[sz]=make_pair(x,i);
    }
    for (int i=1;i<=n;++i){
        p[r[i]-l[i]-1]=max(p[r[i]-l[i]-1],a[i]);
    }
    for (int i=n;i>0;--i)
        p[i]=max(p[i],p[i+1]);
    for (int i=1;i<=n;++i)
        cout<<p[i]<<" ";
}