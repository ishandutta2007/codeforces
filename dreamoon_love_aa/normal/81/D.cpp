#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int special;
struct data{
    int x,y;
    bool operator<(data b)const{
        if(x<b.x)return 1;
        if(x>b.x)return 0;
        if(b.y==special&&y!=b.y)return 1;
        if(y==special&&y!=b.y)return 0;
        return y<b.y;
    }
}a[46];
int an[1010],d[46];
priority_queue<data>heap;
main(){
    int n,m,i,j,k,now=0;
    data tmp1,tmp2,tmp3;
    scanf("%d%d",&n,&m);
    j=-1;
    for(i=0;i<m;i++){
        scanf("%d",&d[i]);
        if(d[i]>=j){
            j=d[i];
            k=i;
        }
    }
    special=k+1;
    an[0]=k+1;
    d[k]--;
    for(i=0;i<m;i++){
        heap.push((data){d[i],i+1});
    }
    for(i=1;i<n;i++){
        tmp1=heap.top();
        if(tmp1.x==0)break;
        heap.pop();
        if(tmp1.y!=an[i-1]&&(i!=n-1||tmp1.y!=an[0])){
            tmp1.x--;
            an[i]=tmp1.y;
            heap.push(tmp1);
        }
        else{
            if(heap.empty())break;
            tmp2=heap.top();
            heap.pop();
            if(tmp2.x==0)break;
            if((i==n-1&&tmp2.y==an[0])||tmp2.y==an[i-1]){
                if(heap.empty())break;
                tmp3=heap.top();
                if(tmp3.x==0)break;
                an[i]=tmp3.y;
                heap.pop();
            }
            else{

                an[i]=tmp2.y;
                tmp2.x--;
                heap.push(tmp1);
                heap.push(tmp2);
            }
        }
    }
    if(i<n)puts("-1");
    else{
        for(i=0;i<n;i++){
            if(i)putchar(' ');
            printf("%d",an[i]);
        }
        puts("");
    }
}