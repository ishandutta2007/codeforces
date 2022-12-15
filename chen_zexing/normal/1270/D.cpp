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
int a[505];
int main() {
    int n,m,k,pos,mth,f,x,y;
    cin>>n>>k;
    int ans=0;
    printf("? ");
    for(int i=1;i<=k;i++) printf("%d ",i);
    printf("\n");
    fflush(stdout);
    scanf("%d%d",&pos,&mth);
    printf("? ");
    for(int i=1;i<=k+1;i++)
        if(i!=pos) printf("%d ",i);
    printf("\n");fflush(stdout);
    scanf("%d%d",&x,&y);
    if(y>mth) f=1;
    else f=0;
    for(int i=1;i<=k;i++)
    {
        if(i==pos) continue;
        printf("? ");
        for(int j=1;j<=k+1;j++) {
            if (j == i) continue;
            printf("%d ",j);
        }
        printf("\n");
        fflush(stdout);
        scanf("%d%d",&x,&y);
        if(y>mth) ans++;
        if(y==mth) ans+=1-f;
    }
    printf("! %d\n",ans+1);
    return 0;
}