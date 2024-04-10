#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[2001][2001];
int pred[2001];
pair<pair<int,int>,int>   v[2500005];
vector<int> vv[2001];
int depth[2001];
int tin[2001];
int rr;
long long l[2001];
int xx,yy,ll;
int sz;
int ss;
int ss2[2001];
bool used[2001];
int zz[100005];
int x,y;
int dp[20][50001];
bool tt;
int ans;
int get(int x){
    if (x==pred[x]) return x;
    else return pred[x]=get(pred[x]);
}
inline bool cmp(pair<pair<int,int> ,int> a,pair<pair<int,int> ,int> b) {
    return a.second<b.second;
}
void dfs(int x,int d,long long len){
    used[x]=true;
    depth[x]=d;
    l[x]=len;
    tin[x]=++sz;
    dp[0][sz]=x;
    for (int i=0;i<vv[x].size();++i) {
        int to=vv[x][i];
        if (used[to]==false) { dfs(to,d+1,len+a[x][to]); ++sz; dp[0][sz]=x; }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            cin>>a[i][j];
            if (i<j) { ++rr; v[rr]=make_pair(make_pair(i,j),a[i][j]); }
            if ((i>j && (a[i][j]!=a[j][i] || a[i][j]==0)) || (i==j && a[i][j])) {
                cout<<"NO";
                return 0;
            }
        }
    }
    sort(v+1,v+rr+1,cmp);
    for (int i=1;i<=n;++i)
        pred[i]=i;
    for (int i=1;i<=rr;++i){
        x=v[i].first.first;
        y=v[i].first.second;
        xx=get(x);
         yy=get(y);
        if (xx!=yy) {
            vv[x].push_back(y);
            vv[y].push_back(x);
            pred[xx]=yy;
            ss2[xx]+=ss2[yy];
            if (ss2[xx]==n) break;
        }
    }
    dfs(1,0,0);
    int ss=1;
    while (ss<sz) ss+=ss;
    for (int i=2;i<=ss;++i)
        zz[i]=zz[i/2]+1;
    for (int i=1;i<=zz[ss];++i){
        for (int j=1;j<=ss-(1<<i)+1;++j){
            x=dp[i-1][j];
            y=dp[i-1][j+(1<<(i-1))];
            if (depth[x]<depth[y]) dp[i][j]=x;
            else dp[i][j]=y;
        }
    }
    for (int i=1;i<=n;++i)
        for (int j=i+1;j<=n;++j) {
        ans=0;
        x=tin[i];
        y=tin[j];
        if (x>y) swap(x,y);
        ll=y-x+1;
        ll=zz[ll];
        xx=dp[ll][x];
         yy=dp[ll][y-(1<<ll)+1];
        if (depth[xx]<depth[yy]) ans=xx;
        else ans=yy;
        if (l[i]-l[ans]+l[j]-l[ans]!=a[i][j]) {
            cout<<"NO";
            return 0;
        }
   }
   cout<<"YES";
}