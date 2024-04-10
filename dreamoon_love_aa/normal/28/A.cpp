#include<stdio.h>
#include<vector>
using namespace std;
struct Point{
    int x,y;
    void scan(){scanf("%d%d",&x,&y);}
}nail[1010];
int d[1010],use[40010];
vector<int>rod[200010];
int abs(int x){return x<0?-x:x;}
main(){
    int n,m,x,i,j=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        nail[i].scan();
    for(i=1;i<=m;i++){
        scanf("%d",&x);
        rod[x].push_back(i);
    }
    nail[n]=nail[0];
    for(i=0;i<n;i++)
        d[i+1]=abs(nail[i].x-nail[i+1].x)+abs(nail[i].y-nail[i+1].y);
    d[0]=d[n];
    
    for(i=0;i<n;i+=2){
        x=d[i]+d[i+1];
        if(use[x]<rod[x].size())use[x]++;
        else break;
    }
    if(i>=n){
        puts("YES");
        for(i=1;i<=40000;i++)use[i]=0;
        for(i=0;i<n;i+=2){
            if(i)putchar(' ');
            x=d[i]+d[i+1];
            printf("%d -1",rod[x][use[x]++]);
        }
        puts("");
    }
    else{
        for(i=1;i<=40000;i++)use[i]=0;
        d[n+1]=d[1];
        for(i=1;i<=n;i+=2){
            x=d[i]+d[i+1];
            if(use[x]<rod[x].size())use[x]++;
            else break;
        }
        if(i<=n)puts("NO");
        else{
            for(i=1;i<=40000;i++)use[i]=0;
            puts("YES");
            for(i=1;i<=n;i+=2){
                if(i!=1)putchar(' ');
                x=d[i]+d[i+1];
                printf("-1 %d",rod[x][use[x]++]);
            }
            puts("");
        }
    }
}