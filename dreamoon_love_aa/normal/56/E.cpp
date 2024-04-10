#include<stdio.h>
#include<algorithm>
#include<stack>
#define SIZE 100000
using namespace std;
struct data{
    int x,h,No;
    bool operator<(data b)const{return x<b.x;}
    void scan(){scanf("%d%d",&x,&h);}
}a[SIZE];
int an[SIZE];
main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)a[i].scan(),a[i].No=i;
    sort(a,a+n);
    stack<int>S;
    for(i=n-1;i>=0;i--){
        an[a[i].No]=1;
        while(!S.empty()){
            if(a[i].x+a[i].h>a[S.top()].x){
                an[a[i].No]+=an[a[S.top()].No];
                S.pop();
            }
            else break;
        }
        S.push(i);
    }
    for(i=0;i<n;i++){
        if(i)putchar(' ');
        printf("%d",an[i]);
    }
    puts("");
}