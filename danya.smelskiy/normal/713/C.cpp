#include <bits/stdc++.h>
using namespace std;

int n;
int a[3005];

struct st{
    int med,l,r;
    vector<int> v;
};
vector<st> q;
inline st add(int x){
    st res;
    res.med=a[x];
    res.v.push_back(a[x]);
    res.l=x;
    res.r=x;
    return res;
}
inline st mrg(st a,st b){
    st res;
    res.l=a.l;
    res.r=b.r;
    res.v.clear();
    int ll=0,rr=0;
    while (ll<a.v.size() || rr<b.v.size()) {
        if (ll==a.v.size()) {
            res.v.push_back(b.v[rr]);
            ++rr;
            continue;
        }
        if (rr==b.v.size()) {
            res.v.push_back(a.v[ll]);
            ++ll;
            continue;
        }
        int x=a.v[ll];
        int y=b.v[rr];
        if (x<=y) {
            res.v.push_back(x);
            ++ll;
        } else {
            res.v.push_back(y);
            ++rr;
        }
    }
    res.med=res.v[(b.r-a.l+2)/2-1];
    return res;
}
void build(){
    for (int i=1;i<=n;++i) {
        q.push_back(add(i));
        while (q.size()>=2 && q[q.size()-2].med>=q[q.size()-1].med) {
            st res=mrg(q[q.size()-2],q[q.size()-1]);
            q.pop_back();
            q[q.size()-1]=res;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        a[i]-=i;
    }
    build();
    long long ans=0;
    for (int i=0;i<q.size();++i) {
        for (int j=q[i].l;j<=q[i].r;++j)
            ans+=abs(a[j]-q[i].med);
    }
    cout<<ans;
}