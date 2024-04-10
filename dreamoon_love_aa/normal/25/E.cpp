#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s[3][1000100];
char now[3000100];
char tmp[3000100];
int an,p[3];
bool used[3];
int Z(char str[],int l){
    static int d[3000100];
    d[0]=0;
    int left=0,right=0,now=0,i,j;
    for(i=1;str[i];i++){
        if(i>=right)j=0;
        else j=min(d[i-left],right-i);
        while(str[j]==str[i+j])j++;
        d[i]=j;
        if(i+j>right){
            left=i;
            right=i+j;
        }
    }
    int len=i;
    for(i=l;i<len;i++)
        if(d[i]>=l||i+d[i]>=len)break;
    if(i==len||d[i]<l){
        memcpy(str+i,str,l);
        memcpy(str,str+l,i);
        str[i]=0;
        return i;
    }
    else{
        memcpy(str,str+l,len-l);
        str[len-l]=0;
        return len-l;
    }
}
void Calc(){
    strcpy(now,s[p[1]]);
    strcat(now,s[p[0]]);
    Z(now,strlen(s[p[1]]));
    strcpy(tmp,now);
    strcpy(now,s[p[2]]);
    strcat(now,tmp);
    an=min(an,Z(now,strlen(s[p[2]])));
}
void dfs(int x){
    int i;
    if(x==3){
        Calc();
        return;
    }
    for(i=0;i<3;i++){
        if(!used[i]){
            used[i]=1;
            p[x]=i;
            dfs(x+1);
            used[i]=0;
        }
    }
}
main(){
    int i;
    an=1000000000;
    for(i=0;i<3;i++)scanf("%s",s[i]);
    dfs(0);
    printf("%d\n",an);
}