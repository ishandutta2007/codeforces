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
int x[100005],y[100005];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
        if(n%2){
            puts("NO");
            continue;
        }
        int f=1;
        for(int i=1;i<n/2;i++)
            if(x[i+1]-x[i]!=x[i+n/2]-x[i+1+n/2]||y[i+1]-y[i]!=y[i+n/2]-y[i+1+n/2])
                f=0;
        if(x[1]-x[n/2]!=x[n]-x[n/2+1]||y[1]-y[n/2]!=y[n]-y[n/2+1]) f=0;
        puts(f?"YES":"NO");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp