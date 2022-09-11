#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int d[1001],a[1001];
struct data{
    int x,y;
    bool operator<(data b)const{return x>b.x;}
}b[1001];
char an[1024][1024];
main(){
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        d[a[i]]++;
    }
    k=0;
    for(i=1000,j=0;i>0;i--){
        if(j%2==1)k=1;
        j/=2;
        j+=d[i];
    }
    if(j>2||(j==2&&k==1))puts("NO");
    else{
        puts("YES");
        for(i=0;i<n;i++)
            b[i]=(data){a[i],i};
        sort(b,b+n);
        for(i=0;i<b[0].x;i++)an[b[0].y][i]='0';
        an[b[0].y][b[0].x]=0;
        for(i=1;i<n;i++){
            strcpy(an[b[i].y],an[b[i-1].y]);
            an[b[i].y][b[i].x]=0;
            an[b[i].y][b[i].x-1]++;
            for(j=b[i].x-1;j>=0&&an[b[i].y][j]>'1';j--){
                an[b[i].y][j]='0';
                an[b[i].y][j-1]++;
            }
        }
        for(i=0;i<n;i++)puts(an[i]);
    }
}