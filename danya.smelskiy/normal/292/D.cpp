#include <bits/stdc++.h>
using namespace std;


int n,m;
int p[1005];
vector<int> qq;
pair<int,int> q[10005];

int get(int x){
    if (x==p[x]) return x;
    else return p[x]=get(p[x]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        cin>>q[i].first>>q[i].second;
    }
    for (int i=1;i<=n;++i)
        p[i]=i;
    for (int i=1;i<=m;++i) {
        int x=q[i].first,y=q[i].second;
        x=get(x);
        y=get(y);
        if (x==y) continue;
        qq.push_back(i);
        p[y]=x;
    }
    for (int i=1;i<=n;++i)
        p[i]=i;
    for (int i=m;i>0;--i) {
        int x=q[i].first,y=q[i].second;
        x=get(x);
        y=get(y);
        if (x==y) continue;
        qq.push_back(i);
        p[y]=x;
    }
    cin>>m;
    for (int i=1;i<=m;++i) {
        int x,y;
        cin>>x>>y;
        for (int j=1;j<=n;++j) {
            p[j]=j;
        }
        int ans=n;
        for (int i=0;i<qq.size();++i){
            if (qq[i]>=x && qq[i]<=y) continue;
            int xx=q[qq[i]].first;
            int yy=q[qq[i]].second;
            xx=get(xx);
            yy=get(yy);
            if (xx==yy) continue;
            p[yy]=xx;
            --ans;
        }
        cout<<ans<<'\n';
    }
}