#include<stdio.h>
#include<algorithm>
using namespace std;
int m[3];
struct data{
    int x,No;
    bool operator<(data b)const{return x>b.x;}
}a[3][100000];
main(){
    int n,v,i,j,x,y,cost=0,an1,an2,ma=0;
    scanf("%d%d",&n,&v);
    for(i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        a[x][m[x]++]=(data){y,i};
    }
    sort(a[1],a[1]+m[1]);
    sort(a[2],a[2]+m[2]);
    for(i=0;i<m[1];i++)cost+=a[1][i].x;
    for(i=m[1],j=0;i>=0;i--){
        if(i+j*2>v){
            if(i)cost-=a[1][i-1].x;
            continue;
        }
        while(j<m[2]&&i+(j+1)*2<=v){
            cost+=a[2][j].x;
            j++;
        }
        if(cost>ma){
            an1=i,an2=j;
            ma=cost;
        }
        if(i)cost-=a[1][i-1].x;
    }
    printf("%d\n",ma);
    if(ma){
        j=0;
        for(i=0;i<an1;i++){
            if(j)putchar(' ');
            else j++;
            printf("%d",a[1][i].No);
        }
        for(i=0;i<an2;i++){
            if(j)putchar(' ');
            else j++;
            printf("%d",a[2][i].No);
        }
        puts("");
    }
    else puts("");
}