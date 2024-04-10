#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
struct data{
    int x,y;
    bool operator<(data b)const{
        return x<b.x||(x==b.x&&y<b.y);
    }
}an[1024];
struct data2{
    int x,y,No;
    bool operator<(data2 b)const{return x>b.x||(x==b.x&&y<b.y);}
}a[1024];
priority_queue<data>q;
main(){
    int N,ma,reg,blood,last,i,j,ann=0,t=0,v;
    scanf("%d%d%d",&N,&ma,&reg);
    for(i=0;i<N;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].No=i+1;
    }
    blood=ma;
    sort(a,a+N);
    last=ma+1;
    i=0;
    v=-reg;
    while(blood>0){
        if(blood>ma)blood=ma;
        if(blood==last)break;
        last=blood;
        while(i<N&&ma*a[i].x>=100*blood){
            q.push((data){a[i].y,a[i].No});
            i++;
        }
        if(!q.empty()){
            an[ann++]=(data){t,q.top().y};
            v+=q.top().x;
            last=ma+1;
            q.pop();
        }
        blood-=v;
        t++;
        
    }
    if(blood>0)puts("NO");
    else{
        puts("YES");
        printf("%d %d\n",t,ann);
        for(i=0;i<ann;i++)printf("%d %d\n",an[i].x,an[i].y);
    }    
}