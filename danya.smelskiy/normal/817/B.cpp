#include <bits/stdc++.h>
using namespace std;


int n;
long long ans;
long long a[100005];
long long b[100005];
pair<long long,long long> q[100005];
long long c[100005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    q[n+1]=make_pair(1e9,0);
    for (int i=n;i>0;--i) {
        q[i]=q[i+1];
        if (a[i]==q[i].first) ++q[i].second;
        else if (a[i]<q[i].first) {
            q[i]=make_pair(a[i],1);
        }
    }
    pair<int,int> t=make_pair(1e9,0);
    for (int i=1;i<n;++i) {
        c[2]=a[i]; c[1]=t.first; c[3]=q[i+1].first;
        if (c[2]<c[1]) swap(c[1],c[2]); if (c[2]>c[3]) swap(c[2],c[3]);
        if (c[2]<c[1]) swap(c[1],c[2]);
        if (c[1]==b[1] && c[2]==b[2] && c[3]==b[3]) {
            ans+=t.second*q[i+1].second;
        }
        if (a[i]<t.first) t=make_pair(a[i],1);
        else if (a[i]==t.first) ++t.second;
    }
    cout<<ans;
}