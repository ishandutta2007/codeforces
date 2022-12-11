#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const char l[5][20]={"Danil","Olya", "Slava", "Ann", "Nikita"};
const int len[5]={5,4,5,3,6};
int main(){
    char buf[110];cin>>buf;int cnt=0,le=strlen(buf);
    
    for(int i=0;i<5;++i){
        char *pos=buf;
        while(buf+le>pos&&(pos=strstr(pos,l[i]))!=NULL)++cnt,pos+=len[i];
    }
    //cout<<cnt<<endl;
    puts(cnt==1?"YES":"NO");
    return 0;
}