#include<stdio.h>
#include<map>
#include<string>
using namespace std;
int used[900];
map<string,int>Map;
main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,k,x,y,i;
    char name[16],type[4];
    scanf("%d%d%d",&n,&m,&k);
    while(k--){
        scanf("%s",type);
        if(type[0]=='+'){
            scanf("%d%d%s",&x,&y,name);
            x--,y--;
            for(i=x*m+y;i<n*m&&used[i];i++);
            if(i!=n*m){
                used[i]=1;
                Map[name]=i;
            }
         /*
            else{
                for(i=0;i<n*m&&used[i];i++);
                if(i!=n*m){
                    used[i]=1;
                    Map[name]=i;
                }
            }
            */
        }
        else{
            scanf("%s",name);
            if(Map.count(name)&&Map[name]!=-1){
                printf("%d %d\n",Map[name]/m+1,Map[name]%m+1);
                used[Map[name]]=0;
                Map[name]=-1;
            }
            else puts("-1 -1");
        }
    }
}