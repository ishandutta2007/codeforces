#include<stdio.h>
char s[256];
main(){
    int n,m,k,first,ma=-1,i,j,win=1,an;
    char dir[8];
    scanf("%d%d%d",&n,&m,&k);
    scanf("%*s%s",dir);
    scanf("%s",s);
    for(i=0;s[i];i++){
        if(dir[0]=='h'){
            if(s[i]=='0'){
                if(m<k){
                    if(m!=1)m--;
                }
                else{
                    if(m!=n)m++;
                }
            }
            else{
                m=k;
            }
            if(k==1){
                dir[0]='x';
                k++;
            }
            else k--;
        }
        else{
            if(s[i]=='0'){
                if(m>k){
                    if(m!=n)m++;
                }
                else{
                    if(m!=1)m--;
                }
            }
            else{
                m=k;
            }
            if(k==n){
                dir[0]='h';
                k--;
            }
            else k++;
        }
        if(m==k)break;
    }
    if(s[i])win=0;
    else win=1;
    an=i+1;
    if(win==1)puts("Stowaway");
    else printf("Controller %d\n",an);
}