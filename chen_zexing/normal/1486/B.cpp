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
int x[1005],y[1005];
long long prex[1005],prey[1005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
        sort(x+1,x+n+1);
        sort(y+1,y+n+1);
        int cntx=0,cnty=0;
        if(n%2){
            cntx=1,cnty=1;
        }
        else{
            cntx=x[n/2+1]-x[n/2]+1;
            cnty=y[n/2+1]-y[n/2]+1;
        }
        printf("%lld\n",1LL*cntx*cnty);
    }
    return 0;
}