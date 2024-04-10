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
int a,b,n,v[10000],bfs[10000];
double an;
struct Point{
    int x,y;
    Point(int _x=0,int _y=0){x=_x,y=_y;}
    Point operator-(const Point& b)const{return Point(x-b.x,y-b.y);}
    void scan(){scanf("%d%d",&x,&y);}
    int dis2(){return x*x+y*y;}
    double dis(){return sqrt(dis2());}
}A,B,line[1024][2];
bool used[1024];
const double eps=1e-9;
double dd(Point X,Point line[2]){
    double res=(line[0]-X).dis();
    res=min(res,(line[1]-X).dis());
    if(line[0].x==line[1].x){
        if((line[0].y-X.y)*(line[1].y-X.y)<=0)res=min(res,(double)abs(line[0].x-X.x));
    }
    if(line[0].y==line[1].y){
        if((line[0].x-X.x)*(line[1].x-X.x)<=0)res=min(res,(double)abs(line[0].y-X.y));
    }
    return res;
}
double dd(Point line1[2],Point line2[2]){
    double res=1e12;
    res=min(res,dd(line1[0],line2));
    res=min(res,dd(line1[1],line2));
    res=min(res,dd(line2[0],line1));
    res=min(res,dd(line2[1],line1));
    return res;
}
int main(){
    an=1e12;
    int i,j,k,n;
    scanf("%d%d",&a,&b);
    A.scan();
    B.scan();
    scanf("%d",&n);
    for(i=0;i<n;i++){line[i][0].scan();line[i][1].scan();}
    if((B-A).dis2()<=a*a){
        printf("%.10lf\n",sqrt((B-A).dis2()));
        return 0;
    }
    for(i=j=0;i<n;i++){
        if(dd(A,line[i])<=a+eps){
            v[j]=1;
            bfs[j++]=i;
            used[i]=1;
        }
    }
    for(i=0;i<j;i++){
        int x=bfs[i];
        //printf("%lf\n",an);
        if(dd(B,line[x])<=a+eps){
            //printf("[%d]\n",v[i]);
            an=min(an,v[i]*(a+b)+dd(B,line[x]));
        }
        for(k=0;k<n;k++){
            if(used[k])continue;
            if(dd(line[x],line[k])<a+eps){
                used[k]=1;
                v[j]=v[i]+1;
                bfs[j++]=k;
            }
        }
    }
    if(an>1e9)puts("-1");
    else printf("%.9lf\n",an);
    return 0;
}