#include <bits/stdc++.h>
using namespace std;


int n;
vector<int> v[100];
int cnt[100];
pair<long long,long long> ans[100];


void dfs(int x,int y,long long xx,long long yy,int dir,long long len) {
    ans[x]=make_pair(xx,yy);
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        ++dir;
        dir%=4;
        long long xx2=xx,yy2=yy;
        if (dir==0) yy2-=len;
        else if (dir==1) xx2+=len;
        else if (dir==2) yy2+=len;
        else xx2-=len;
        dfs(to,x,xx2,yy2,(dir+2)%4,len/2);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        ++cnt[x];
        ++cnt[y];
    }
    for (int i=1;i<=n;++i)
    if (cnt[i]>=5) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<'\n';
    dfs(1,-1,0,0,-1,(1<<n));
    for (int i=1;i<=n;++i)
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}