#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct data{
    int x,y;
    bool operator<(data b)const{return x<b.x||(x==b.x&&y<b.y);}
}d[1024];
bool is_digit(char c){return c>='0'&&c<='9';}
main(){
    char s[65536];
    int a,neg=0,n=0,y,an=0,i,len;
    scanf("%d%s",&a,s);
    len=strlen(s);
    for(i=0;i<len;i++){
        if(is_digit(s[i])){
            y=atoi(s+i);
            while(is_digit(s[i]))i++;
            i++;
        }
        else y=1;
        if(neg)y=-y;
        if(s[i]=='+')d[n].y=1;
        else d[n].y=0;
        d[n++].x=y;
        i+=3;
        if(s[i]=='+')neg=0;
        else neg=1;
        if(!s[i])break;
    }
    sort(d,d+n);
    for(i=0;i<n;i++){
        if(d[i].y==1){
            a++;
            an+=d[i].x*a;
        }
        else{
            an+=d[i].x*a;
            a++;
        }
    }
    printf("%d\n",an);
}