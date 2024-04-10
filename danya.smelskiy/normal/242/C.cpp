#include <bits/stdc++.h>
using namespace std;


int x,y,xx,yy,n,l,r;
map<pair<int,int>,int> depth;
map<pair<int,int>,bool> used,u;
pair<int,int> q[100005];

inline void chek(int x,int y,int xx,int yy){
    if (used[make_pair(x,y)]) return;
    if (u[make_pair(x,y)]==false) return;
    used[make_pair(x,y)]=true;
    depth[make_pair(x,y)]=depth[make_pair(xx,yy)]+1;
    ++r;
    q[r]=make_pair(x,y);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>y>>xx>>yy;
    cin>>n;
    for (int i=1;i<=n;++i) {
        int r,x2,y2;
        cin>>r>>x2>>y2;
        for (int i=x2;i<=y2;++i)
            u[make_pair(r,i)]=true;
    }
    l=1,r=1;
    q[1]=make_pair(x,y);
    used[make_pair(x,y)]=true;
    while (l<=r) {
        int x2=q[l].first;
        int y2=q[l].second;
        ++l;
        chek(x2-1,y2-1,x2,y2);
        chek(x2-1,y2,x2,y2);
        chek(x2-1,y2+1,x2,y2);
        chek(x2,y2+1,x2,y2);
        chek(x2,y2-1,x2,y2);
        chek(x2,y2-1,x2,y2);
        chek(x2+1,y2-1,x2,y2);
        chek(x2+1,y2,x2,y2);
        chek(x2+1,y2+1,x2,y2);
    }
    if (x==xx && y==yy) cout<<0;
    else if (depth[make_pair(xx,yy)]==0) cout<<"-1";
    else cout<<depth[make_pair(xx,yy)];
}