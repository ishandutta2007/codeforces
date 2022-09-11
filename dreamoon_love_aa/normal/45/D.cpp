#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int an[128];
struct date{
    int x,y,No;
    bool operator<(date b)const{return x<b.x;}
}a[128];
struct data{
    int x,y;
    bool operator<(data b)const{return x>b.x;}
};
priority_queue<data>X;
main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].No=i;
    }
    sort(a,a+n);
    for(i=1,j=0;i<=10000000;i++){
        while(j<n&&a[j].x==i){
            X.push((data){a[j].y,a[j].No});
            j++;
        }
        if(!X.empty()){
            if(X.top().x<i)break;
            an[X.top().y]=i;
            X.pop();
        }
    }
    for(i=0;i<n;i++){
        if(i)putchar(' ');
        printf("%d",an[i]);
    }
    puts("");
}