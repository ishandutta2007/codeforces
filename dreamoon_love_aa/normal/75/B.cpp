#include<stdio.h>
#include<map>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
map<string,int>Map;
struct data{
    string s;
    int score;
    bool operator<(data b)const{
        return score>b.score||(score==b.score&&strcmp(s.c_str(),b.s.c_str())<0);
    }
}a[10000];
main(){
    int n,x,score,i;
    char M[64];
    char s[64],tmp[2][64];
    scanf("%s",M);
    scanf("%d",&n);
    while(n--){
        scanf("%s%s",tmp[0],tmp[1]);
        if(tmp[1][0]=='l'){
            scanf("%s%*s",tmp[1]);
            score=5;
        }
        else{
            if(tmp[1][0]=='p')score=15;
            else score=10;
            scanf("%*s%s%*s",tmp[1]);
        }
        tmp[1][strlen(tmp[1])-2]=0;
        if(strcmp(tmp[0],M)==0)x=1;
        else if(strcmp(tmp[1],M)==0)x=0;
        else x=-1;
        if(x!=-1){
            if(Map.count(tmp[x])==0){
                Map[tmp[x]]=score;
            }
            else{
                Map[tmp[x]]+=score;
            }
        }
        else{
            if(Map.count(tmp[0])==0)Map[tmp[0]]=0;
            if(Map.count(tmp[1])==0)Map[tmp[1]]=0;
        }
    }
    map<string,int>::iterator it;
    x=0;
    for(it=Map.begin();it!=Map.end();it++){
        a[x++]=(data){it->first,it->second};
    }
    sort(a,a+x);
    for(i=0;i<x;i++)puts(a[i].s.c_str());
}