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
long long x[105],y[105];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%lld%lld",&x[i],&y[i]);
        int fl=0;
        for(int i=1;i<=n;i++){
            int f=1;
            for(int j=1;j<=n;j++)
                if(i!=j&&abs(x[i]-x[j])+abs(y[i]-y[j])>k)
                    f=0;
            if(f) fl=1;
        }
        if(fl) puts("1");
        else puts("-1");
    }
    return 0;
}