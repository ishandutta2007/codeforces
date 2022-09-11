#include<stdio.h>
#include<algorithm>
int dx[5]={1,0,-1,0,0};
int dy[5]={0,1,0,-1,0};
struct Point{
    int x,y;
    void scan(){scanf("%d%d",&x,&y);}
    bool operator==(Point b){return x==b.x&&y==b.y;}
}a[3];
int sqr(int x){return x*x;}
int Test(){
    int d[3];
    d[0]=sqr(a[0].x-a[1].x)+sqr(a[0].y-a[1].y);
    d[1]=sqr(a[0].x-a[2].x)+sqr(a[0].y-a[2].y);
    d[2]=sqr(a[1].x-a[2].x)+sqr(a[1].y-a[2].y);
    if(d[0]==0||d[1]==0||d[2]==0)return 0;
    std::sort(d,d+3);
    if(d[0]+d[1]==d[2])return 1;
    return 0;
}
main(){
    int i,j,an=0,tmp;
    for(i=0;i<3;i++)a[i].scan();
    for(i=0;i<3;i++){
        for(j=0;j<5;j++){
            a[i].x+=dx[j];
            a[i].y+=dy[j];
            tmp=Test();
            if(tmp==1){
                if(j==4)an=std::max(an,2);
                else an=std::max(an,1);
            }
            a[i].x-=dx[j];
            a[i].y-=dy[j];
        }
        if(j<5)break;
    }
    if(an==0)puts("NEITHER");
    else if(an==1)puts("ALMOST");
    else puts("RIGHT");
}