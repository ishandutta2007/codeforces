#include<stdio.h>
#include<string>
#include<map>
using namespace std;
map<string,int>H;
main(){
    int n,i;
    char s[99];
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        if(!H.count(s)){
            puts("OK");
            H[s]=1;
        }
        else
            printf("%s%d\n",s,H[s]++);
    }
}