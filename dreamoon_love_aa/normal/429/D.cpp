#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int SIZE = 100000;
const double EPS = 1e-12;
struct Point{
    double x,y;
    int id;
    Point(double _x=0,double _y=0,int _id=0):x(_x),y(_y),id(_id){}
    bool operator<(const Point& b)const{
        if(fabs(x-b.x)<EPS)return y<b.y;
        return x<b.x;
    }
    Point operator-(const Point& b){return Point(x-b.x,y-b.y);}
    double dis(){return sqrt(x*x+y*y);}
}p[SIZE],r_p[17][SIZE];
int left[SIZE],tt;
vector<Point>a[2];
double cal(int L,int R,int lv){
    if(R<=L)return 1e24;
    if(R-L==1)return (p[L]-p[R]).dis();
    int mm=(L+R)>>1;
    tt++;
    for(int i=L;i<=mm;i++)
        left[p[i].id]=tt;
    int lid=L,rid=mm+1;
    for(int i=L;i<=R;i++){
        if(left[r_p[lv][i].id]==tt)r_p[lv+1][lid++]=r_p[lv][i];
        else r_p[lv+1][rid++]=r_p[lv][i];
    }
    double d1=cal(L,mm,lv+1);
    double d2=cal(mm+1,R,lv+1);
    double md=min(d1,d2);
    double mx=(p[mm+1].x+p[mm].x)*0.5;
    a[0].clear();
    a[1].clear();
    for(int i=L;i<=mm;i++)if(fabs(r_p[lv+1][i].y-mx)<md)a[0].push_back(r_p[lv+1][i]);
    for(int i=mm+1;i<=R;i++)if(fabs(r_p[lv+1][i].y-mx)<md)a[1].push_back(r_p[lv+1][i]);
    int now=0;
    for(int i=0;i<(int)a[0].size();i++){
        while(now<(int)a[1].size()&&a[1][now].x+md<a[0][i].x)now++;
        for(int j=0;now+j<(int)a[1].size()&&a[1][now+j].x<a[0][i].x+md;j++)md=min(md,(a[0][i]-a[1][now+j]).dis());
    }
    return md;
}
int main(){
    int N;
    while(scanf("%d",&N)==1&&N){
        double now=0;
        for(int i=0;i<N;i++){
            double x,y;
            scanf("%lf",&y);
            now+=y;
            x=i;
            p[i]=Point(x,now,i);
            r_p[0][i]=Point(now,x,i);
        }
        sort(p,p+N);
        sort(r_p[0],r_p[0]+N);
        double an=cal(0,N-1,0);
        an*=an;
        printf("%d\n",(int)(an+0.5));
    }
    return 0;
}