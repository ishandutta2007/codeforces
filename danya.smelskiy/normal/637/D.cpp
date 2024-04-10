#include <bits/stdc++.h>
using namespace std;
const long long inf=1e10;
long long n,m,s,d;
long long a[200005];
pair<long long,long long> q[200005];
int sz;
vector<pair<int,long long> > ans;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>s>>d;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    ++n;
    a[n]=inf;
    sort(a+1,a+n+1);
    if (a[1]<=s) {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    sz=1;
    int v=-1;
    q[1]=make_pair(0,a[1]-1);
    if (q[1].second>=m) {
        v=1;
    }
    else {
    for (int i=2;i<=n;++i){
            if ((a[i]-a[i-1]-2>=s) || (m>a[i-1] && m<a[i])) {
                ++sz;
                q[sz]=make_pair(a[i-1]+1,a[i]-1);
                if (a[i]>m) {
                    v=sz;
                    break;
                }
            }
            if (a[i]>m) break;
    }
    }
    if (v==-1) {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    int now=1;
    while (now<v) {
        ans.push_back(make_pair(0,q[now].second-q[now].first));
        int z=-1;
        for (int i=now+1;i<=v;++i){
            long long xx=q[i].first;
            if (xx-q[now].second<=d) z=i; else break;
        }
        if (z==-1) {
            cout<<"IMPOSSIBLE";
            return 0;
        }
        ans.push_back(make_pair(1,q[z].first-q[now].second));
        now=z;
    }
    if (m!=q[v].first) ans.push_back(make_pair(0,m-q[v].first));
    for (int i=0;i<ans.size();++i){
        if (ans[i].first==0) cout<<"RUN ";
        else cout<<"JUMP ";
        cout<<ans[i].second<<'\n';
    }
}