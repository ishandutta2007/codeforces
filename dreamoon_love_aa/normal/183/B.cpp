#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
struct Point{
    long long x,y;
    Point(long long _x=0,long long _y=0){x=_x,y=_y;}
    void scan(){cin>>x>>y;}
    Point operator-(const Point& b)const{return Point(x-b.x,y-b.y);}
    long long operator*(const Point& b)const{return x*b.y-y*b.x;}

}p[259];
int res[1000001];
int main(){
    int i,j,k,n,m,an=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)res[i]=1;
    for(i=0;i<m;i++)p[i].scan();
    for(i=0;i<m;i++)
        for(j=i+1;j<m;j++){
            if(p[i].y==p[j].y)continue;
            long long g=__gcd(abs(p[i].x-p[j].x),abs(p[i].y-p[j].y));
            if(p[i].y%(abs(p[i].y-p[j].y)/g)==0){
                int cnt=0;
                for(k=0;k<m;k++){
                    if((p[j]-p[i])*(p[k]-p[i])==0)cnt++;
                }
                long long tmp=p[i].x+(p[j].x-p[i].x)*(0-p[i].y)/(p[j].y-p[i].y);
                if(tmp>0&&tmp<=n)res[tmp]=max(res[tmp],cnt);
            }
        }
    for(i=1;i<=n;i++)an+=res[i];
    cout<<an<<endl;
    return 0;
}