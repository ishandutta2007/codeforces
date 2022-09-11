#include<stdio.h>
#include<string.h>
char S[5][9]={"S", "M", "L", "XL","XXL"};
int abs(int x){return x<0?-x:x;}
main(){
    int a[5],n,i,j,k,an;
    char s[9];
    for(i=0;i<5;i++)scanf("%d",&a[i]);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",s);
        for(j=0;j<5&&strcmp(s,S[j]);j++);
        an=10;
        for(k=4;k>=0;k--){
            if(a[k]&&abs(k-j)<abs(an-j)){
                an=k;
            }
        }
        puts(S[an]);
        a[an]--;
    }
}