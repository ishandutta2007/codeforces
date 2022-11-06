#include<bits/stdc++.h>
using namespace std;
char s[20];
void work(){
    scanf("%s",s);
    int n=strlen(s),i;
    if(n==2)printf("%c\n",s[1]);
    else{
        char c='9';
        for(i=0;i<n;++i){
            if(s[i]<c)c=s[i];
        }
        printf("%c\n",c);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}