#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int n;

struct pt{
    int x,y;
};
bool cmp(const pt&a,const pt&b){
    return a.x==b.x?a.y<b.y:a.x<b.x;
}
int main(){
    cin>>n;
    vector<pt> p(n+1);
    vector<bool> ok(n+1,1);
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
    }
    int u=1;ok[1]=0;cout<<1<<' ';
    for(int i=2;i<=n;i++){
        long long mdis=0;int mid;
        for(int j=1;j<=n;j++){
            if(ok[j]){
                long long dis=(p[u].x-p[j].x)*(long long)(p[u].x-p[j].x)+(p[u].y-p[j].y)*(long long)(p[u].y-p[j].y);
                if(dis>mdis){
                    mdis=dis;mid=j;
                }
            }
        }
        ok[u=mid]=0;
        cout<<u<<' ';
    }
    return 0;
}