#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<stdlib.h>
#define pb push_back
using namespace std;
#define SIZE 200010
#define MAX 1000000000000000ll
#define EPS 1e-9
struct Point{
    long long x,y;
    Point(long long _x=0,long long _y=0){x=_x,y=_y;}
    void scan(){scanf("%I64d%I64d",&x,&y);}
    bool operator<(Point b)const{return x<b.x||(x==b.x&&y<b.y);}
    Point operator-(Point b)const{return Point(x-b.x,y-b.y);}
    long long operator*(Point b){return x*b.y-y*b.x;}
}p[SIZE],mi,ma;
vector<Point>down,up;
int main(){
    int T,i,n,j,Q,mi_pos,ma_pos,x,y;
    down.clear();
    up.clear();
    scanf("%d",&n);
    mi=Point(MAX,MAX);
    ma=Point(-MAX,-MAX);
    for(i=0;i<n;i++){
        p[i].scan();
    }
    for(i=0;i<n-1-i;i++)swap(p[i],p[n-1-i]);
    for(i=0;i<n;i++){
        p[n+i]=p[i];
        if(p[i]<mi){
            mi=p[i];
            mi_pos=i;
        }
        if(ma<p[i]){
            ma=p[i];
            ma_pos=i;
        }
    }
    if(ma_pos<mi_pos)
        for(i=mi_pos;i<=ma_pos+n;i++)down.push_back(p[i]);
    else
        for(i=mi_pos;i<=ma_pos;i++)down.push_back(p[i]);
    if(down[down.size()-2].x==down.back().x)down.pop_back();
    if(mi_pos<ma_pos)
        for(i=mi_pos+n;i>=ma_pos;i--)up.push_back(p[i]);
    else
        for(i=mi_pos;i>=ma_pos;i--)up.push_back(p[i]);
    if(up[0].x==up[1].x)up.erase(up.begin());
    scanf("%d",&Q);
    while(Q--){
        Point now;
        now.scan();
        if(now.x<=up[0].x||now.x>=up.back().x){
            puts("NO");
            return 0;
        }
        int pos=lower_bound(up.begin(),up.end(),Point(now.x,-MAX))-up.begin();
        if(!pos)pos++;
        if((up[pos]-up[pos-1])*(now-up[pos-1])>=0){
            puts("NO");
            return 0;
        }
        pos=lower_bound(down.begin(),down.end(),Point(now.x,-MAX))-down.begin();
        if(!pos)pos++;
        if((down[pos]-down[pos-1])*(now-down[pos-1])<=0){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}