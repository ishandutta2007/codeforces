#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
struct data{
    int x,y,No;
    bool operator<(data b)const{return x>b.x||(x==b.x&&y>b.y)||(x==b.x&&y==b.y&&No<b.No);}
    void scan(int z){scanf("%d%d",&x,&y),No=z;}
}a[200000];
struct data2{
    int x,No;
    bool operator<(data2 b)const{return x<b.x||(x==b.x&&No<b.No);}
};
priority_queue<data2>heap;
int an[100000],ann;
main(){
    int T,i,now,n,j;
    scanf("%d",&T);
    while(T--){
        while(!heap.empty())heap.pop();
        scanf("%d",&n);
        for(i=0;i<n+n-1;i++)a[i].scan(i+1);
        sort(a,a+n+n-1);
        i=now=0;
        while(now<n){
            while(i<now+now+1){
                heap.push((data2){a[i].y,a[i].No});
                i++;
            }
            an[now++]=heap.top().No;
            heap.pop();
        }
        puts("YES");
        sort(an,an+n);
        for(i=0;i<n;i++){
            if(i)putchar(' ');
            printf("%d",an[i]);
        }
        puts("");
    }
}