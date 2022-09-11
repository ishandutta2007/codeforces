#include<stdio.h>
#include<set>
#include<string>
#include<string.h>
using namespace std;
set<string>H;
main(){
    int i,an=0;
    char s[999];
    while(gets(s)!=NULL){
        if(s[0]=='+')
            H.insert(s+1);
        else if(s[0]=='-')
            H.erase(s+1);
        else{
            for(i=0;s[i]!=':';i++);
            s[i]=0;
            an+=strlen(s+i+1)*H.size();
        }
    }
    printf("%d\n",an);
}