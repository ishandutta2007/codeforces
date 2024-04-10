#include<stdio.h>
#include<algorithm>
using namespace std;
int min(int x,int y){return x<y?x:y;}
char s[1000010];
int d[1000010];
void error(){puts("Just a legend");}
int main(){
    int T,left,right,i,k;
    scanf("%s",s);
    for(i=1,left=0;s[i];i++){
        if(i<left+d[left])
            k=min(d[i-left],left+d[left]-i);
        else
            k=0;
        for(;s[i+k];k++){
            if(s[i+k]!=s[k])break;
        }
        d[i]=k;
        if(i+k>left+d[left])left=i;
    }
    int len=i;
    if(len<3){
        error();
        return 0;
    }
    int ma=0;
    for(i=1;i<len;i++){
        if(i+d[i]==len&&ma>=d[i])break;
        ma=max(ma,d[i]);
    }
    if(i==len)error();
    else puts(s+i);
        
}