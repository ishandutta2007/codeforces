#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int ans[100005],xxor[100005],bl[100005];
int main() {
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        printf("XOR %d %d\n",1,i);
        fflush(stdout);
        scanf("%d",&xxor[i]);
    }
    int f=1,p;
    bl[0]=1;
    for(int i=2;i<=n;i++){
        if(bl[xxor[i]]){
            f=0;
            printf("AND %d %d\n",i,bl[xxor[i]]);
            fflush(stdout);
            scanf("%d",&ans[i]);
            ans[bl[xxor[i]]]=ans[i];
            p=i;
            break;
        }
        bl[xxor[i]]=i;
    }
    if(!f){
        if(!ans[1]) ans[1]=xxor[p]^ans[p];
        for(int i=2;i<=n;i++)
            if(!ans[i])
                ans[i]=xxor[i]^ans[1];
    }
    else{
        int t,t2;
        for(int i=2;i<=n;i++){
            if(xxor[i]==1){
                printf("AND 1 %d\n",i);
                fflush(stdout);
                scanf("%d",&t);
                break;
            }
        }
        f=0;
        for(int i=2;i<=n;i++){
            if(xxor[i]%2==0){
                f=1;
                printf("AND 1 %d\n",i);
                fflush(stdout);
                scanf("%d",&t2);
                if(t2%2) t++;
                break;
            }
        }
        if(!f){
            printf("AND 2 3\n");
            scanf("%d",&t2);
            if(t2%2==0) t++;
        }
        ans[1]=t;
        for(int i=2;i<=n;i++) ans[i]=xxor[i]^ans[1];
    }
    printf("! ");
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    puts("");
    return 0;
}