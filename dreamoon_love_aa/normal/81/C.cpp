#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100000],an[100000];
main(){
    int now=0,x,y,i,j,n;
    scanf("%d%d%d",&n,&x,&y);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    if(x==y){
        for(i=0;i<x;i++){
            if(i)putchar(' ');
            printf("1");
        }
        for(;i<n;i++)printf(" 2");
        puts("");
    }
    else{
        if(x<y){
            for(i=5;i>=1;i--){
                for(j=0;j<n;j++){
                    if(a[j]==i){
                        if(now<x)an[j]=1;
                        else an[j]=2;
                        now++;
                    }
                }
            }
        }
        else{
            for(i=1;i<=5;i++){
                for(j=0;j<n;j++){
                    if(a[j]==i){
                        if(now<x)an[j]=1;
                        else an[j]=2;
                        now++;
                    }
                }
            }
        }
        for(i=0;i<n;i++){
            if(i)putchar(' ');
            printf("%d",an[i]);
        }
        puts("");
    }

}