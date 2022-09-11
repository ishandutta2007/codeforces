#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
using namespace std;
int an;
map<string,int>H;
bool is_alpha(char c){return c>='A'&&c<='Z';}
void f(char s[],int &offset){
    if(s[offset]==0)return;
    int i;
    char name[16];
    for(i=offset;is_alpha(s[i]);i++);
    strncpy(name,s+offset,i-offset);
    name[i-offset]=0;
    if(H.count(name)==0){
        H[name]=1;
    }
    else H[name]++;
    an+=H[name]-1;
    offset=i;
    if(s[offset]==':'){
        do{
            offset++;
            f(s,offset);
        }while(s[offset]==',');
    }
    offset++;
    H[name]--;
}
main(){
    char s[1024];
    gets(s);
    int tmp=0;
    f(s,tmp);
    printf("%d\n",an);
}