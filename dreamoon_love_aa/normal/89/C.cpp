#include<stdio.h>
#include<string.h>
#define SIZE 5012
char s[SIZE];
int O[SIZE][4],list[SIZE][4];
int n,m;
int get(int x,int y){return x*m+y;}
void Init(int a[][4]){
    int i,j,flag,now,p;
    for(i=0;i<m;i++){
        flag=0;
        for(j=0;j<n;j++){
            p=get(j,i);
            if(s[p]==-1)continue;
            if(flag){
                a[p][0]=now;
            }
            else{
                a[p][0]=-1;
                flag=1;
            }
            now=p;
        }
    }
    for(i=0;i<m;i++){
        flag=0;
        for(j=n-1;j>=0;j--){
            p=get(j,i);
            if(s[p]==-1)continue;
            if(flag){
                a[p][2]=now;
            }
            else{
                a[p][2]=-1;
                flag=1;
            }
            now=p;
        }
    }
    for(i=0;i<n;i++){
        flag=0;
        for(j=m-1;j>=0;j--){
            p=get(i,j);
            if(s[p]==-1)continue;
            if(flag){
                a[p][1]=now;
            }
            else{
                a[p][1]=-1;
                flag=1;
            }
            now=p;
        }
    }
    for(i=0;i<n;i++){
        flag=0;
        for(j=0;j<m;j++){
            p=get(i,j);
            if(s[p]==-1)continue;
            if(flag){
                a[p][3]=now;
            }
            else{
                a[p][3]=-1;
                flag=1;
            }
            now=p;
        }
    }
}
void del(int pos){
    int i;
    for(i=0;i<4;i++)
        if(list[pos][i]>=0)list[list[pos][i]][i^2]=list[pos][i^2]; 
}
int count(int pos){
    int an=1;
    while(list[pos][s[pos]]>=0){
        del(pos);
        pos=list[pos][s[pos]];
        an++;
    }
    return an;
}
main(){
    int ma=0,an=0,i,j,k,nm;
    scanf("%d%d",&n,&m);
    nm=n*m;
    for(i=0;i<n;i++)scanf("%s",s+i*m);
    for(i=0;i<nm;i++){
        if(s[i]=='U')s[i]=0;
        else if(s[i]=='R')s[i]=1;
        else if(s[i]=='D')s[i]=2;
        else if(s[i]=='L')s[i]=3;
        else if(s[i]=='.')s[i]=-1;
    }
    Init(O);
    for(i=0;i<nm;i++){
        if(s[i]==-1)continue;
        memcpy(list,O,sizeof(list));
        int tmp=count(i);
        if(tmp>ma){
            ma=tmp;
            an=1;
        }
        else if(tmp==ma)an++;
    }
    printf("%d %d\n",ma,an);
}