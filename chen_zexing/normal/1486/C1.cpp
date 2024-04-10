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
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        int l,r,temp,t;
        printf("? %d %d\n",1,n);
        fflush(stdout);
        scanf("%d",&temp);
        printf("? %d %d\n",1,max(2,temp));
        fflush(stdout);
        scanf("%d",&t);
        if(t==temp){
            if(temp==1){
                printf("! %d\n",2);
                return 0;
            }
            else{
                l=1,r=temp-1;
                while(l<r){
                    int mid=(l+r)>>1;
                    mid++;
                    printf("? %d %d\n",mid,temp);
                    fflush(stdout);
                    scanf("%d",&t);
                    if(t==temp) l=mid;
                    else r=mid-1;
                }
                printf("! %d\n",l);
            }
        }
        else{
            l=temp+1,r=n;
            while(l<r){
                int mid=(l+r)>>1;
                printf("? %d %d\n",temp,mid);
                fflush(stdout);
                scanf("%d",&t);
                if(t==temp) r=mid;
                else l=mid+1;
            }
            printf("! %d\n",l);
        }
    }
    return 0;
}