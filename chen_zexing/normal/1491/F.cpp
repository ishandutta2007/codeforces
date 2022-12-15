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
int f[2005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,ans;
        cin>>n;
        ans=n;
        for(int i=1;i<=n;i++) f[i]=-1;
        int p=-1,t;
        for(int i=2;i<=n;i++){
            printf("? %d %d\n",i-1,1);
            for(int j=1;j<i;j++) printf("%d ",j);
            puts("");
            printf("%d\n",i);
            fflush(stdout);
            scanf("%d",&t);
            if(t){
                p=i;
                break;
            }
        }
        f[p]=1,ans--;
        for(int i=p+1;i<=n;i++){
            printf("? %d %d\n",1,1);
            printf("%d\n%d\n",p,i);
            fflush(stdout);
            scanf("%d",&t);
            if(t) f[i]=1,ans--;
        }
        int l=1,r=p-1;
        while(l<r){
            int mid=(l+r)>>1;
            printf("? %d %d\n",mid,p-mid);
            for(int i=1;i<=mid;i++) printf("%d ",i);
            puts("");
            for(int i=mid+1;i<=p;i++) printf("%d ",i);
            puts("");
            fflush(stdout);
            scanf("%d",&t);
            if(t) r=mid;
            else l=mid+1;
        }
        f[l]=1,ans--;
        printf("! %d ",ans);
        for(int i=1;i<=n;i++) if(f[i]==-1) printf("%d ",i);
    }
    return 0;
}