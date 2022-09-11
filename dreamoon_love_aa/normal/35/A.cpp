#include<stdio.h>
#include<algorithm>
using namespace std;
int a[3];
main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int x,y,i;
    scanf("%d",&x);
    a[x-1]=1;
    for(i=0;i<3;i++){
        scanf("%d%d",&x,&y);
        swap(a[x-1],a[y-1]);
    }
    for(i=0;i<3;i++)
        if(a[i])break;
    printf("%d\n",++i);
}