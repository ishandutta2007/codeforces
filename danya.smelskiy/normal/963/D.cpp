#include <bits/stdc++.h>
using namespace std;
const unsigned long long md=1e9+7;


int n;
string s;
int m;
unsigned long long p[100007];
unsigned long long h[100007];
map<unsigned long long,int> pos;
vector<int> v[100005];
int ans[100005];
string b[100005];
pair<int,pair<int,int> > a[100005];

inline unsigned long long get_hash(string &x) {
    unsigned long long res=0;
    for (int i=1;i<=x.size();++i) {
        res=(res+(x[i-1]-'a'+1)*(p[i]));
    }
    res=(res*p[100004]);
    return res;
}


inline void build(int len) {
    unsigned long long cur=0;
    int x;
    for (int i=len;i<=n;++i) {
        cur=h[i]-h[i-len];
        if (cur<0) cur+=md;
        cur=(cur*p[100005-(i-len+1)]);
        if (pos.count(cur)) {
            v[pos[cur]].push_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    s="#"+s;
    n=s.size()-1;
    p[0]=1;
    for (int i=1;i<=100005;++i)
        p[i]=(p[i-1]*31);
    for (int i=1;i<=n;++i)
        h[i]=(h[i-1]+(s[i]-'a'+1)*p[i]);
    cin>>m;
    for (int i=1;i<=m;++i) {
        cin>>a[i].second.first;
        a[i].second.second=i;
        cin>>b[i];
        a[i].first=b[i].size();
    }
    sort(a+1,a+m+1);
    int i=1;
    int cur;
    int x,y;
    while (i<=m) {
        int j=i;
        while (j<=m && a[j].first==a[i].first) ++j;
        for (int k=i;k<j;++k){
            x=a[k].second.second;
            pos[get_hash(b[x])]=k;
        }
        build(a[i].first);
        for (int k=i;k<j;++k) {
            x=a[k].second.second;
            ans[x]=-1;
            y=a[k].second.first;
            if (v[k].size()>=y) {
                for (int z=y;z<=v[k].size();++z) {
                    cur=v[k][z-1];
                    cur-=v[k][z-y];
                    cur+=b[x].size();
                    if (ans[x]==-1 || cur<ans[x]) ans[x]=cur;
                }
            }
            v[k].clear();
        }
        pos.clear();
        i=j;
    }
    for (int i=1;i<=m;++i)
        cout<<ans[i]<<'\n';
}