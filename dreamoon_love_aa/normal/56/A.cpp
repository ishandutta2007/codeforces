#include<stdio.h>
#include<set>
#include<string>
#include<stdlib.h>
using namespace std;
char s[11][20]={"ABSINTH","BEER","BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
set<string>H;
main(){
    int i,an=0,n;
    char tmp[99];
    for(i=0;i<11;i++)H.insert(s[i]);
    scanf("%d",&n);
    while(n--){
        scanf("%s",tmp);
        if(tmp[0]>='0'&&tmp[0]<='9'){
            if(atoi(tmp)<18)an++;
        }
        else if(H.count(tmp))an++;
    }
    printf("%d\n",an);
}