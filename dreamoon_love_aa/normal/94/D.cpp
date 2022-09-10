#include<stdio.h>
#include<vector>
using namespace std;
struct data{
    int x,y;
};
vector<data>d[51];
main(){
    int i,n,m,now,No,re,count,w;
    scanf("%d%d%d",&n,&w,&m);
    now=0;
    No=1;
    for(i=1;i<=n;i++){
        count=0;
        re=m;
        while(now+re>=n){
            count++;
            d[No++].push_back((data){n-now,i});
            re-=n-now;
            now=0;
        }
        if(re){
            count++;
            now+=re;
            d[No].push_back((data){re,i});
        }
        if(count>2)break;
    }
    if(i<=n)puts("NO");
    else{
        puts("YES");
        for(i=1;i<=m;i++){
            for(int j=0;j<d[i].size();j++){
                if(j)putchar(' ');
                printf("%d %.6lf",d[i][j].y,1.*d[i][j].x*w/m);
            }
            puts("");
        }
    }
}