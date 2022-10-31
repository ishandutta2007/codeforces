#include <bits/stdc++.h>
using namespace std;




int n,m,kol,cnt,all;

vector<int> qqq;
int used2[505];
int pred[505];

bool used[505];
vector<int> v[505];
vector<int> vv[505];
int clr[505];
vector<int> qq;
vector<int> q;
void dfs(int x) {
    used[x]=true;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (used[to]==false) dfs(to);
    }
    q.push_back(x);
}

void dfs2(int x,int y) {
    clr[x]=y;
    ++cnt;
    for (int i=0;i<vv[x].size();++i) {
        int to=vv[x][i];
        if (clr[to]==0) dfs2(to,x);
    }
}

bool dfs3(int x,int y) {
    used2[x]=1;
    pred[x]=y;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (used2[to]==2) continue;
        if (used2[to]==0) {
            if (dfs3(to,x)) return true;
            continue;
        }
        while (x!=to) {
            qqq.push_back(x);
            x=pred[x];
        }
        qqq.push_back(to);
        return true;
    }
    used2[x]=2;
    return false;
}
bool dfs4(int x,int y,int xx,int yy) {
    used2[x]=1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (x==xx && to==yy) continue;
        if (used2[to]==2) continue;
        if (used2[to]==0) {
            if (dfs4(to,x,xx,yy)) return true;
            continue;
        }
        return true;
    }
    used2[x]=2;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        vv[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
        if (used[i]==false) dfs(i);
    reverse(q.begin(),q.end());
    for (int i=0;i<q.size();++i) {
        int x=q[i];
        if (clr[x]) continue;
        cnt=0;
        ++all;
        dfs2(x,all);
        if (cnt>=2) {
            ++kol;
            qq.push_back(x);
        }
    }
    if (kol>=2) {
        cout<<"NO";
        return 0;
    }
    if (kol==0) {
        cout<<"YES";
        return 0;
    }
    dfs3(qq[0],-1);
    reverse(qqq.begin(),qqq.end());
    for (int i=0;i<qqq.size();++i) {
        int x=qqq[i];
        int y;
        if (i<qqq.size()-1) y=qqq[i+1];
        else y=qqq[0];
        memset(used2,0,sizeof(used2));
        bool t=false;
        for (int i=1;i<=n;++i)
        if (dfs4(i,-1,x,y)) {
            t=true;
            break;
        }
        if (t==false) {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}