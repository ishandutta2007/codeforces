#include <bits/stdc++.h>
using namespace std;

struct st{
    int kol,id,d;
};
st t;
int n,m,kol,id,d;
vector<pair<int,int> > v;
st b[100001];
int sz;
int a[100001];
inline bool cmp(st a,st b){
    return a.d<b.d;
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        t.kol=0;
        t.id=i;
        t.d=a[i];
        b[i]=t;
    }
    sort(b+1,b+n+1,cmp);
    ++sz;
    if (b[1].d!=0) {
        cout<<"-1";
        return 0;
    }
    for (int i=2;i<=n;++i){
        kol=b[i].kol;
        id=b[i].id;
        d=b[i].d;
        while (b[sz].kol==m || b[sz].d<d-1) { ++sz; if (sz>=i) {cout<<"-1"; return 0;}}
        if (b[sz].kol==m || !(b[sz].d==b[i].d-1)) {
            cout<<"-1";
            return 0;
        }
        ++b[sz].kol;
        ++b[i].kol;
        v.push_back(make_pair(b[sz].id,b[i].id));
    }
    cout<<v.size()<<'\n';
    for (int i=0;i<v.size();++i)
        cout<<v[i].first<<" "<<v[i].second<<'\n';
}