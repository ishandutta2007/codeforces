#include<stdio.h>
char s[111];
main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n=0,i,j,last=-1,d=-1,end=0;
    scanf("%d %s",&n,s);
    for(i=0;i<n;i++){
        if(s[i]=='1'){
            if(last>-1){
                if(d>-1){
                    if(d!=i-last){
                        end=1;
                    }
                }
                else d=i-last;
            }
            last=i;
        }
    }
    if(end==0&&last>-1)puts("YES");
    else puts("NO");
}