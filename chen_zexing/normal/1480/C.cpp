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
int n;
int query(int x){
    if(x==0||x==n+1) return 999999;
    printf("? %d\n",x);
    fflush(stdout);
    int t;
    scanf("%d",&t);
    return t;
}
int ans[100005],con[100005];
int check(int x){
    if(!ans[x-1]) ans[x-1]=query(x-1);
    if(!ans[x]) ans[x]=query(x);
    if(!ans[x+1]) ans[x+1]=query(x+1);
    if(ans[x]<ans[x+1]&&ans[x]<ans[x-1]) return 2;
    else if(ans[x]>ans[x+1]) return 1;
    else return 0;
}
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        cin>>n;
        int l=1,r=n;
        if(l==r){
            puts("! 1");
            continue;
        }
        ans[r]=query(r);
        if(ans[r]==1){
            printf("! %d\n",r);
            return 0;
        }
        ans[l]=query(l);
        if(ans[l]==1){
            printf("! %d\n",l);
            return 0;
        }
        con[1]=1,con[n]=0;
        while(l<r){
            int mid=(l+r)>>1;
            if(!ans[mid]) ans[mid]=query(mid);
            int t=check(mid);
            if(t==2){
                printf("! %d\n",mid);
                return 0;
            }
            con[mid]=t;
            if(t==1){
                l=mid+1;
            }
            else r=mid;
        }
        printf("! %d\n",l);
    }
    return 0;
}