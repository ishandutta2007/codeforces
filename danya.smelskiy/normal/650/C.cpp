#include <bits/stdc++.h>
using namespace std;

int n,m;
int y,x,z;
map<pair<int,int>,int> r1,r2;
int pred[1000005];
int a[1000005];
vector<int> v[1000005];
vector<int> v2[1000005];
map<int,int> last1,last2;
int order[1000005];
int to,qq;
int minim=0;
int pos=0;
vector<int> order2;
int dp[1000005];
bool used[1000005];
int get(int x){
    if (x==pred[x]) return x;
    else return pred[x]=get(pred[x]);
}
inline bool cmp(int c,int b){
    return a[c]<a[b];
}
void dfs(int x){
    used[x]=true;
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i];
        if (used[to]==false) dfs(to);
    }
    order2.push_back(x);
}
void dfs2(int x){
    dp[x]=1;
    for (int i=0;i<v2[x].size();++i){
        int to=v2[x][i];
        if (dp[to]) { dp[x]=max(dp[x],dp[to]+1); continue;}
        dfs2(to);
        dp[x]=max(dp[x],dp[to]+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n*m;++i) {
        cin>>a[i];
        pred[i]=i;
        order[i]=i;
        if (a[i]>minim) {
            minim=a[i];
            pos=i;
        }
    }
    for (int i=1;i<=n*m;++i) {
        x=a[i];
        z=i/m;
        if (i%m) ++z;
        if (r1[make_pair(x,z)]) {
            y=r1[make_pair(x,z)];
            y=get(y);
            pred[y]=i;
        }
        r1[make_pair(x,z)]=i;
        z=i%m;
        if (z==0) z=m;
        if (r2[make_pair(x,z)]) {
            y=r2[make_pair(x,z)];
            y=get(y);
            pred[y]=i;
        }
        r2[make_pair(x,z)]=i;
    }
    sort(order+1,order+n*m+1,cmp);
    for (int i=1;i<=n*m;++i) {
        qq=order[i];
        x=qq/m;
        if (qq%m) ++x;
        if (last1[x]!=0) {
            y=last1[x];
            if (a[y]<a[qq]) { v2[get(qq)].push_back(y); v[y].push_back(get(qq)); }
        }
        last1[x]=get(qq);
        x=qq%m;
        if (x==0) x=m;
        if (last2[x]!=0) {
            y=last2[x];
            if (a[y]<a[qq]) { v2[get(qq)].push_back(y); v[y].push_back(get(qq)); }
        }
        last2[x]=get(qq);
    }
   for (int i=1;i<=n*m;++i)
    if (dp[get(i)]==0) dfs2(get(i));
    for (int i=order2.size()-1;i>=0;--i) {
        dp[order2[i]]=max(dp[order2[i]],1);
        for (int j=0;j<v[order2[i]].size();++j){
            to=v[order2[i]][j];
            dp[to]=max(dp[to],dp[order2[i]]+1);
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j) {
            cout<<dp[get((i-1)*m+j)]<<" ";
        }
        cout<<'\n';
    }
}