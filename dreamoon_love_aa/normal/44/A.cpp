#include<stdio.h>
#include<set>
#include<string.h>
using namespace std;
struct data{
    char s1[99],s2[99];
    bool operator<(data b)const{return strcmp(s1,b.s1)<0||(strcmp(s1,b.s1)==0&&strcmp(s2,b.s2)<0);}
};
set<data>H;
main(){
    int n,i,an=0;
    char s1[99],s2[99];
    data tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s%s",tmp.s1,tmp.s2);
        if(H.count(tmp)==0){
            H.insert(tmp);
            an++;
        }
    }
    printf("%d\n",an);
}