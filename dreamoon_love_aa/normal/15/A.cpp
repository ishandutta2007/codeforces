#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
struct data{
    int x,y;
    bool operator<(data b)const{return x<b.x;}
}a[1010];
set<int>answer;
main(){
    int n,t,x,y,m=0,i;
    scanf("%d%d",&n,&t);
    t*=2;
    while(n--){
        scanf("%d%d",&x,&y);
        a[m++]=(data){x+x-y,x+x+y};
    }
    sort(a,a+m);
    n=0;
    for(i=0;i<m;i++){
        if(i==0)answer.insert(a[i].x-t/2);
        else{
            if(a[i].x-a[i-1].y>=t)answer.insert(a[i].x-t/2);
        }
        if(i+1==m)answer.insert(a[i].y+t/2);
        else{
            if(a[i+1].x-a[i].y>=t)answer.insert(a[i].y+t/2);
        }
    }
    printf("%d\n",answer.size());
}