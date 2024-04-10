#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int dx[4]={0,0,-1,1};
const int dy[4]={1,-1,0,0};
struct node{
    int x,y;
};
int n,m,r,k;
set<node> vis;

long long calc(long long x,long long y){
    return (min(x+r-1,(long long)n)-max(x,(long long)(r))+1)*(min(y+r-1,(long long)m)-max(y,(long long)(r))+1);
}
struct cmp{
    bool operator () (node a,node b){
        return calc(a.x,a.y)<calc(b.x,b.y);
    }
};
bool operator<(node a,node b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
int main(){
    cin>>n>>m>>r>>k;
    priority_queue<node,vector<node>,cmp> q;
    node st;st.x=((n+1)/2),st.y=((m+1)/2);
    q.push(st);
    double ans=0;
    double qf=(long long)(n-r+1)*(m-r+1);
    vis.insert(st);
    while(k--){
        node u=q.top();q.pop();
        ans+=calc(u.x,u.y)/qf;
        for(int i=0;i<4;i++){
            int nx=u.x+dx[i],ny=u.y+dy[i];
            if(nx<1||ny<1||nx>n||ny>m) continue;
            node v;v.x=nx;v.y=ny;
            if(vis.find(v)==vis.end()){
                vis.insert(v);
                q.push(v);
            }
        }
    }
    cout<<fixed<<setprecision(20)<<ans;
    return 0;
}