#include<cstdio>
int main(){
    int n;
    scanf("%d",&n);
    char s[1000];
    int an=1;
    scanf("%s",s);
    for(int i=0;i<n;i++){
        if(s[i]=='1')an++;
        else break;
    }
    if(an>n)an=n;
    printf("%d\n",an);
    return 0;
}