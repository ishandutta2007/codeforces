#include<stdio.h>
#include<vector>
using namespace std;
int cal;
struct road{
    int d,y,c;
};
vector<road>Map[110];
void Go(int x,int last){
    int u;
    if(Map[x][0].y==last)u=1;
    else u=0;
    if(Map[x][u].d==0)cal+=Map[x][u].c;
    if(Map[x][u].y!=1)Go(Map[x][u].y,x);
}
main(){
    int i,n,x,y,c,an;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d%d",&x,&y,&c);
        Map[x].push_back((road){1,y,c});
        Map[y].push_back((road){0,x,c});
    }
    cal=0;
    if(Map[1][0].d==0)
        cal+=Map[1][0].c;
    Go(Map[1][0].y,1);
    an=cal;
    cal=0;
    if(Map[1][1].d==0)
        cal+=Map[1][1].c;
    Go(Map[1][1].y,1);
    if(an>cal)an=cal;
    printf("%d\n",an);
}