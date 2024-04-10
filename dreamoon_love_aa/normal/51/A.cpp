#include<stdio.h>
bool used[10000];
int an;
int To(char c){return c-'0';}
void Add(int a,int b,int c,int d){
    int e[4],mi=10000;
    e[0]=a*1000+b*100+c*10+d;
    e[1]=b*1000+c*100+d*10+a;
    e[2]=c*1000+d*100+a*10+b;
    e[3]=d*1000+a*100+b*10+c;
    for(int i=0;i<4;i++){
        if(mi>e[i])mi=e[i];
    }
    if(!used[mi]){
        an++;
        used[mi]=1;
    }
}
main(){
    int n,i,start=0;
    char s[4][4];
    scanf("%d",&n);
    while(n--){
        if(start)scanf("%*s");
        else start=1;
        scanf("%s%s",s[0],s[1]);
        Add(To(s[0][0]),To(s[0][1]),To(s[1][1]),To(s[1][0]));
    }
    printf("%d\n",an);
}