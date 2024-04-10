#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

int n,m;
string s;
int h[27][200105];
int sz;
long long p[200005];
vector<int> v[26];



long long res;
int len;

inline void calc(int x) {
    for (int i=1;i<=n;++i) {
        h[x][i]=h[x][i-1];
        if (s[i]-'a'==x) h[x][i]+=(13*1ll*p[i])%md;
        else h[x][i]+=(3*1ll*p[i])%md;
        if (h[x][i]>=md) h[x][i]-=md;
    }
}

inline long long get_hash(int x,int l,int r) {
    int res=h[x][r]-h[x][l-1];
    if (res<0) res+=md;
    res=(res*1ll*p[n+5-l])%md;
    return res;
}


inline int get_f(int x,int ll,int rr) {
    int l=0;
    int r=v[x].size()-1;
    if (l>r) return 0;
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (v[x][mid]>=ll) r=mid;
        else l=mid;
    }
    if (v[x][l]>=ll) r=l;
    if (v[x][r]>=ll && v[x][r]<=rr) return v[x][r];
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    sz=1;
    while (sz<n) sz+=sz;
    p[0]=1;
    for (int i=1;i<=n+5;++i)
        p[i]=(p[i-1]*31)%md;
    cin>>s;
    s="#"+s;
    for (int i=0;i<26;++i)
        calc(i);
    for (int i=1;i<=n;++i) {
        v[s[i]-'a'].push_back(i);
    }
    int x,y,l;
    vector<pair<int,int> > cur1,cur2;
    int xx;
    while (m--) {
        cin>>x>>y>>l;
        cur1.clear(); cur2.clear();
        for (int i=0;i<26;++i) {
            xx=get_f(i,x,x+l-1);
            if (xx)
            cur1.push_back(make_pair(xx,i));
            xx=get_f(i,y,y+l-1);
            if (xx)
            cur2.push_back(make_pair(xx,i));
        }
        if (cur1.size()!=cur2.size()) {
            cout<<"NO"<<'\n';
            continue;
        }
        sort(cur1.begin(),cur1.end());
        sort(cur2.begin(),cur2.end());
        bool t=false;
        for (int i=0;i<cur1.size();++i)
        if (get_hash(cur1[i].second,x,x+l-1)!=get_hash(cur2[i].second,y,y+l-1)) {
            t=true;
            break;
        }
        if (t) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }
}