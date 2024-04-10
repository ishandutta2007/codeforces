#include <stdio.h>
#include <stdlib.h>
typedef struct player{
    int no;
    int abi;
}Player;
int cmp(const void *a,const void *b)
{
    if( ((Player*)a)->abi > ((Player*)b)->abi ) return 1;
    else if( ((Player*)a)->abi == ((Player*)b)->abi ) return 0;
    else return -1;
}
int main()
{
    int n;
    Player p[100000];
    scanf("%d",&n);
    int k;
    for(k=0;k<n;k++){
        scanf("%d",&p[k].abi);
        p[k].no=k+1;
    }
    qsort(p,n,sizeof(Player),cmp);
    if(n%2==0){
        printf("%d\n",n/2);
        for(k=0;k<n;k+=2) printf("%d ",p[k].no);
        printf("\n%d\n",n/2);
        for(k=1;k<n;k+=2) printf("%d ",p[k].no);
    }
    else
    {
        printf("%d\n",n/2+1);
        for(k=0;k<n-2;k+=2) printf("%d ",p[k].no);
        printf("%d",p[n-2].no);
        printf("\n%d\n",n/2);
        for(k=1;k<n-2;k+=2) printf("%d ",p[k].no);
        printf("%d",p[n-1].no);
    }
    return 0;
}