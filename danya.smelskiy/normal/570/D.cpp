#include <bits/stdc++.h>
using namespace std;

int sz;
int timer;
pair<int,pair<int,int> >  a[500005];
int n,m,x;
vector<int> v[500005];
int tin[500005];
int tout[500005];
string s;
int f[500005];
int last[500005];
int dp[500005];
int y;


void dfs(int x,int d){
    ++sz;
    ++timer;
    tin[x]=timer;
    a[sz]=make_pair(d,make_pair(x,timer));
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        dfs(to,d+1);
    }
    tout[x]=timer;
}
inline bool cmp(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b){
    if (a.first!=b.first) return a.first<b.first;
    else return a.second.second<b.second.second;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=2;i<=n;++i) {
        cin>>x;
        v[x].push_back(i);
    }
    cin>>s;
    dfs(1,1);
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;++i) {
        if (a[i].first!=a[i-1].first) f[a[i].first]=i;
        last[a[i].first]=i;
    }
    for (int i=1;i<=n;++i) {
        dp[i]=dp[i-1];
        int x=a[i].second.first;
        x=s[x-1]-'a';
        dp[i]^=(1<<x);
    }
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        if (f[y]==0) {
            cout<<"Yes"<<'\n';
            continue;
        }
        int l=f[y];
        int r=last[y];
        while (l<r-1) {
            int mid=(l+r)>>1;
            if (a[mid].second.second>=tin[x]) r=mid;
            else l=mid;
        }
        if (a[l].second.second>=tin[x]) r=l;
        if (a[r].second.second<tin[x]) {
            cout<<"Yes"<<'\n';
            continue;
        }
        int ll=f[y];
        int rr=last[y];
        while (ll<rr-1) {
            int mid=(ll+rr)>>1;
            if (a[mid].second.second<=tout[x]) ll=mid;
            else rr=mid;
        }
        if (a[rr].second.second<=tout[x]) ll=rr;
        int res=dp[ll]^dp[r-1];
        int kol=0;
        for (int i=0;i<26;++i)
            kol+=(bool)(res&(1<<i));
        if (kol<=1) cout<<"Yes";
        else cout<<"No";
        cout<<'\n';
    }
}