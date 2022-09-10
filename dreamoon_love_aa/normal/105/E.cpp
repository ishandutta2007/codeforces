#include<stdio.h>
#include<algorithm>
using namespace std;
int abs(int x){return x<0?-x:x;}
int used[512][42][42][42];
int a[3][3],an,holden[3],hold[3];
void dfs(int r,int b[]){
    if(used[r][b[0]][b[1]][b[2]])return;
    used[r][b[0]][b[1]][b[2]]=1;
    int i,j,k;
    an=max(max(an,b[0]),max(b[1],b[2]));
    for(i=0;i<3;i++)
        for(j=0;j<3;j++){
            k=1<<(i*3+j);
            if(!(k&r)){
                if(!j&&holden[i]==-1&&hold[i]==-1){
                    for(int it=-a[i][1];it<=a[i][1];it++){
                        if(it+b[i]<=0)continue;
                        int q;
                        for(q=0;q<3;q++)
                            if(it+b[i]==b[q])break;
                        if(q==3){
                            b[i]+=it;
                            dfs(r|k,b);
                            b[i]-=it;
                        }
                    }
                }
                if(j==1&&holden[i]==-1){
                    for(int q=0;q<3;q++)
                        if(abs(b[q]-b[i])==1&&holden[q]==-1){
                            int tmp=b[q];
                            holden[q]=i;
                            hold[i]=q;
                            b[q]=b[i];
                            dfs(k|r,b);
                            b[q]=tmp;
                            holden[q]=-1;
                            hold[i]=-1;
                        }
                }
                if(j==2&&hold[i]!=-1&&holden[i]==-1){
                    if(hold[hold[i]]==-1){
                        for(int it=-a[i][2];it<=a[i][2];it++){
                            if(it+b[i]<=0)continue;
                            int q;
                            for(q=0;q<3;q++)
                                if(it+b[i]==b[q])break;
                            if(q==3){
                                int tmp=hold[i];
                                int p_tmp=b[tmp];
                                b[tmp]=b[i]+it;
                                holden[tmp]=-1;
                                hold[i]=-1;
                                dfs(r|k,b);
                                b[tmp]=p_tmp;
                                holden[tmp]=i;
                                hold[i]=tmp;
                            }
                        }
                    }
                    else{
                        for(int it=-a[i][2];it<=a[i][2];it++){
                            if(!it)continue;
                            int tmp=hold[i];
                            int d_tmp=b[hold[tmp]]-b[tmp];
                            int p_tmp=b[tmp];
                            b[tmp]=b[i]+it;
                            b[hold[tmp]]+=d_tmp;
                            hold[i]=-1;
                            holden[tmp]=-1;
                            dfs(r|k,b);
                            hold[i]=tmp;
                            holden[tmp]=i;
                            b[tmp]=p_tmp;
                            b[hold[tmp]]=b[tmp]+d_tmp;
                        }
                    }
                }
            }
        }
}
main(){
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)scanf("%d",&a[i][j]);
    hold[0]=hold[1]=hold[2]=holden[0]=holden[1]=holden[2]=-1;
    int b[3]={a[0][0],a[1][0],a[2][0]};
    dfs(0,b);
    printf("%d\n",an);
}