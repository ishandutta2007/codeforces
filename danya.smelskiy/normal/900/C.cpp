#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int pref[100005];
int suff[100005];
pair<int,int> q[100005];
vector<int> v[100005];
int p[100005];
int sz;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    for (int i=1;i<=n;++i) {
        while (sz && q[sz].first<a[i]) --sz;
        if (sz==0) {
            p[i]=1;
        } else {
            v[q[sz].second].push_back(i);
        }
        q[++sz]=make_pair(a[i],i);
    }
    for (int i=1;i<=n;++i) {
        pref[i]=pref[i-1]+p[i];
    }
    for (int i=n;i>0;--i)
        suff[i]=suff[i+1]+p[i];
    int ans=-1;
    int mx=0;
    int pos=1e9;
    for (int i=1;i<=n;++i) {
        int res=pref[i-1];
        for (int j=0;j<v[i].size();++j) {
            int to=v[i][j];
            if (a[to]>mx) ++res;
        }
        res+=suff[i+1];
        if (res>ans || (res==ans && a[i]<pos)) {
            ans=res;
            pos=a[i];
        }
        mx=max(mx,a[i]);
    }
    cout<<pos;
}