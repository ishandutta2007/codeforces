#include<cstdio>
int max(int x,int y){return x>y?x:y;}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int an=-1;
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x+(y>0)>m)continue;
        if(y)an=max(an,100-y);
        else an=max(an,0);
    }
    printf("%d\n",an);
    return 0;
}