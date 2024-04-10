#include<stdio.h>
#include<algorithm>
using namespace std;
struct Line{
    int x1,y1,x2,y2;
    void scan(){scanf("%d%d%d%d",&x1,&y1,&x2,&y2);}
}a[4];
struct Line2{
    int type,v,l,r;
    bool operator<(Line2 b)const{
        if(type<b.type)return 1;
        if(type>b.type)return 0;
        if(v<b.v)return 1;
        if(v>b.v)return 0;
        return 0;
    }
}b[4];
main(){
    int i;
    for(i=0;i<4;i++)
        a[i].scan();
    for(i=0;i<4;i++){
        if(a[i].x1==a[i].x2)b[i]=(Line2){0,a[i].x1,min(a[i].y1,a[i].y2),max(a[i].y1,a[i].y2)};
        else if(a[i].y1==a[i].y2)b[i]=(Line2){1,a[i].y1,min(a[i].x1,a[i].x2),max(a[i].x1,a[i].x2)};
        else break;
    }
    if(i<4)puts("NO");
    else{
        sort(b,b+4);
        if(b[1].type!=0||b[2].type!=1)puts("NO");
        else{
            if(b[0].v==b[1].v||b[2].v==b[3].v)puts("NO");
            else{
                for(i=0;i<4;i+=2){
                    if(b[i].l!=b[i+1].l||b[i].r!=b[i+1].r)break;
                }
                if(i<4)puts("NO");
                else{
                    if(b[0].l!=b[2].v||b[0].r!=b[3].v||b[2].l!=b[0].v||b[2].r!=b[1].v)puts("NO");
                    else puts("YES");
                }
            }
        }
    }

}