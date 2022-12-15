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
long long cal(int x,int r){
    return 1LL*x*r+r;
}
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int a,b;
        long long ans=0;
        scanf("%d%d",&a,&b);
        for(int i=1;i<b;i++){
            int l=i+1,r=b;
            while(l<r){
                int mid=(l+r)>>1;
                mid++;
                if(cal(mid,i)<=a) l=mid;
                else r=mid-1;
            }
            //cout<<l-i<<endl;
            if(l==i+1&&cal(l,i)>a) break;
            ans+=l-i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}