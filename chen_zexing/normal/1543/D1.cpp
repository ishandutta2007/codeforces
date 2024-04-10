#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
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
using namespace std;
int query(int x){
    printf("%d\n",x);
    fflush(stdout);
    int t;
    scanf("%d",&t);
    return t;
}
int xxor(int x,int y,int k){
    int ans=0,fac=1;
    while(x||y){
        ans+=((x%k)+(y%k))%k*fac;
        fac*=k;
        x/=k,y/=k;
    }
    return ans;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        int mask=0;
        for(int i=n-1;i>=0;i--){
            int t=query(xxor(i,mask,k));
            if(t) break;
            else mask=xxor(mask,xxor(mask,i,k),k);
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//