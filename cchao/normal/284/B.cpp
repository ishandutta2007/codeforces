#include <cstdio>
int n,c;
int a=0,f=0,i=0;
int main(){
    scanf("%d", &n);
    while((c=getchar())!=EOF){
        switch(c){
            case 'A':++a;break;
            case 'F':++f;break;
            case 'I':++i;break;
        }
    }
    int ans=0;
    if(i==0) ans = a;
    else if(i==1) ans = i;
    printf("%d\n", ans);
    return 0;
}