#include<stdio.h>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
int en,group[3],in[7],dif,num,like,p[3];
struct Edge{
    int x,y;
}e[64];
map<string,int>H;
int f(){
    int an=0,i;
    for(i=0;i<en;i++){
        if(in[e[i].x]==in[e[i].y])an++;
    }
    return an;
}
void dfs(int x){
    int i;
    if(x==7){
        int score=0,ma=-1,mi=2000000001,tmp,mi_num;
        for(i=0;i<3;i++){
            if(group[i]==0)return;
            tmp=p[i]/group[i];
            score+=tmp;
            ma=max(ma,tmp);
            mi=min(mi,tmp);
        }
        if(ma-mi<dif){
            dif=ma-mi;
            like=f();
        }
        else if(ma-mi==dif){
            tmp=f();
            if(tmp>like)like=tmp;
        }
        
        return;
    }
    for(i=0;i<3;i++){
        group[i]++;
        in[x]=i;
        dfs(x+1);
        group[i]--;
    }
}
main(){
    int i;
    dif=2000000001;
    num=0;
    like=0;
    H["Anka"]=0;
    H["Chapay"]=1;
    H["Cleo"]=2;
    H["Troll"]=3;
    H["Dracul"]=4;
    H["Snowy"]=5;
    H["Hexadecimal"]=6;
    int n;
    char s1[16],s2[16];
    scanf("%d",&n);
    while(n--){
        scanf("%s%*s%s",s1,s2);
        e[en++]=(Edge){H[s1],H[s2]};
    }
    for(i=0;i<3;i++)scanf("%d",&p[i]);
    dfs(0);
    printf("%d %d\n",dif,like);
}