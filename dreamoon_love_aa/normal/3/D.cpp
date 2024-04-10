#include<stdio.h>
#include<queue>
using namespace std;
#define SIZE 50010
#define MAX 1000000000000ll
char s[SIZE];
long long d[SIZE];
struct data{
    int x, y;
    bool operator<(data b)const{return x>b.x;}
};
priority_queue<data>Heap;
main(){
    int i,x,y;
    long long an=0;
    gets(s);
    for(i=0;s[i];i++){
        if(s[i]!='?'){
            d[i]=MAX;
        }
        else{
            scanf("%d%d",&x,&y);
            s[i]=')';
            an+=y;
            d[i]=x-y;
        }
    }
    for(i=x=0;s[i];i++){
        if(s[i]=='(')x++;
        else{
            if(d[i]!=MAX)Heap.push((data){d[i],i});
            x--;
            if(x<0){
                if(Heap.empty())break;
                s[Heap.top().y]='(';
                an+=Heap.top().x;
                d[Heap.top().y]*=-1;
                Heap.pop();
                x+=2;
            }
        }
    }
    if(s[i]||x)puts("-1");
    else printf("%I64d\n%s\n",an,s);
}