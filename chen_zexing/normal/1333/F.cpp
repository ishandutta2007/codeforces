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
int ans[500005],f[5000005];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) f[i]=1;
        int rest=n/2,now=n;
        while(rest>1){
            for(int j=rest*2;j<=n;j+=rest)
                if(f[j]==1){
                    f[j]=0;
                    ans[now--]=rest;
                }
            rest--;
        }
        while(now) ans[now--]=1;
        for(int i=2;i<=n;i++) printf("%d ",ans[i]);
    }
    return 0;
}
//
/// 
//01
// 
//