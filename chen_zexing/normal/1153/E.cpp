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
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int r[1005],c[1005],n;
int query(int x1,int y1,int x2,int y2){
    printf("? %d %d %d %d\n",x1,y1,x2,y2);
    fflush(stdout);
    int t;
    scanf("%d",&t);
    return t;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++) r[i]=query(i,1,i,n)%2,cnt+=r[i];
        if(cnt==0){
            for(int i=1;i<=n;i++) c[i]=query(1,i,n,i)%2;
            int p1=0,p2=0;
            for(int i=1;i<=n;i++) if(c[i]){
                    if(!p1) p1=i;
                    else p2=i;
                }
            int l=1,r=n;
            while(l<r){
                int mid=(l+r)>>1;
                int temp=query(1,p1,mid,p1)%2;
                if(temp) r=mid;
                else l=mid+1;
            }
            printf("! %d %d %d %d\n",l,p1,l,p2);
        }
        else{
            cnt=0;
            for(int i=1;i<=n;i++) c[i]=query(1,i,n,i)%2,cnt+=c[i];
            if(cnt==0){
                int p1=0,p2=0;
                for(int i=1;i<=n;i++) if(r[i]){
                        if(!p1) p1=i;
                        else p2=i;
                    }
                int l=1,r=n;
                while(l<r){
                    int mid=(l+r)>>1;
                    int temp=query(p1,1,p1,mid)%2;
                    if(temp) r=mid;
                    else l=mid+1;
                }
                printf("! %d %d %d %d\n",p1,l,p2,l);
            }
            else{
                int x1=0,x2=0,y1=0,y2=0;
                for(int i=1;i<=n;i++) if(r[i]){
                        if(!x1) x1=i;
                        else x2=i;
                    }
                for(int i=1;i<=n;i++) if(c[i]){
                        if(!y1) y1=i;
                        else y2=i;
                    }
                int temp=query(x1,y1,x1,y1)%2;
                if(temp) printf("! %d %d %d %d\n",x1,y1,x2,y2);
                else printf("! %d %d %d %d\n",x1,y2,x2,y1);
            }
        }
    }
    return 0;
}
//
/// 
//01
//