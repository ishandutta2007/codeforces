#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
int sz;
pair<long long,int> q[1000005];
int sz2;
int x;
long long ans=1e18;

inline long long solve(int l,int r) {
    deque<long long > q1,q2;
    q1.clear();
    q2.clear();
    long long res=0;
    for (int i=l;i<=r;++i) {
        if (q[i].second==0) {
            if (q2.empty()) q1.push_back(q[i].first);
            else {
                res=max(res,q[i].first-q2.front());
                q2.pop_front();
            }
        } else {
            if (q1.empty()) q2.push_back(q[i].first);
            else {
                res=max(res,q[i].first-q1.front());
                q1.pop_front();
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>x;
        q[++sz]=make_pair(x,0);
    }
    for (int i=1;i<=n;++i) {
        cin>>x;
        q[++sz]=make_pair(x,1);
    }
    sort(q+1,q+sz+1);
    sz2=sz;
    for (int i=1;i<=sz;++i) {
        ++sz2;
        q[sz2].second=q[i].second;
        q[sz2].first=q[i].first+m;
    }
    int l=1;
    int r=sz2-sz+1;
    while (l<r-2) {
        int m1=l+(r-l+1)/3;
        int m2=r-(r-l+1)/3;
        if (solve(m1,m1+sz-1)<=solve(m2,m2+sz-1)) r=m2;
        else l=m1;
    }
    for (int i=l-80;i<=l+80;++i)
        if (i>=1 && i+sz-1<=sz2) ans=min(ans,solve(i,i+sz-1));
    long long mx=0;
    int pos=1;
    for (int i=1;i<=sz;++i)
    if (q[i+1].first-q[i].first>mx) {
        mx=q[i+1].first-q[i].first;
        pos=i;
    }
    for (int i=pos-80;i<=pos+80;++i)
        if (i>=1 && i+sz-1<=sz2) ans=min(ans,solve(i,i+sz-1));
    cout<<ans;
}