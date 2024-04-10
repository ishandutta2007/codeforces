#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int a[10];
int p[10]={0,4,8,15,16,23,42};
int query(int x,int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int t;
    scanf("%d",&t);
    return t;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int p1=query(1,2),p2=query(2,3),f=0;
        for(int i=1;i<=6&&!f;i++)
            for(int j=1;j<=6&&!f;j++)
                for(int k=1;k<=6&&!f;k++){
                    if(i==j||i==k||j==k) continue;
                    if(p[i]*p[j]==p1&&p[j]*p[k]==p2){
                        a[1]=p[i],a[2]=p[j],a[3]=p[k];
                        f=1;
                    }
                }
        p1=query(4,5),p2=query(5,6),f=0;
        for(int i=1;i<=6&&!f;i++)
            for(int j=1;j<=6&&!f;j++)
                for(int k=1;k<=6&&!f;k++){
                    if(i==j||i==k||j==k) continue;
                    if(p[i]*p[j]==p1&&p[j]*p[k]==p2){
                        a[4]=p[i],a[5]=p[j],a[6]=p[k];
                        f=1;
                    }
                }
        printf("! ");
        for(int i=1;i<=6;i++) printf("%d ",a[i]);
    }
    return 0;
}
//
/// 
//01
//