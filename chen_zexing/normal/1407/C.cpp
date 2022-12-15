#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int ans[10005];
int main() {
    int n,p=1,m1,m2;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        printf("? %d %d\n",p,i);
        fflush(stdout);
        scanf("%d",&m1);
        printf("? %d %d\n",i,p);
        fflush(stdout);
        scanf("%d",&m2);
        if(m1>m2){
            ans[p]=m1;
            p=i;
        }
        else{
            ans[i]=m2;
        }
    }
    ans[p]=n;
    printf("! ");
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    printf("\n");
    fflush(stdout);
    return 0;
}