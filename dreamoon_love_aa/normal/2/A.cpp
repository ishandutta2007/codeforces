#include<stdio.h>
#include<map>
#include<string>
using namespace std;
map<string,int>H;
int person,d[1000],e[1000];
struct AHA{
    char s[99];
}name[1000];
struct data{
    int x,y;
}a[1000];
main(){
    int i,x,ma,N;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%s%d",name[person].s,&x);
        if(H.count(name[person].s)==0){
            H[name[person].s]=person;
            a[i]=(data){person,x};
            person++;
        }
        else{
            a[i]=(data){H[name[person].s],x};
        }
        d[a[i].x]+=x;
    }
    ma=0;
    for(i=0;i<person;i++)
        if(ma<d[i])ma=d[i];
    for(i=0;i<N;i++){
        e[a[i].x]+=a[i].y;
        if(e[a[i].x]>=ma&d[a[i].x]==ma)break;
    }
    printf("%s\n",name[a[i].x].s);
}