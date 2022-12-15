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
int a[200005];
long long pre[200005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        n+=2;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
        int f=0;
        for(int i=1;i<n;i++){
            if(pre[n-1]-a[i]==a[n]){
                f=1;
                for(int j=1;j<n;j++) if(j!=i) printf("%d ",a[j]);
                puts("");
                break;
            }
        }
        if(f) continue;
        if(pre[n-2]==a[n-1]){
            f=1;
            for(int i=1;i<=n-2;i++) printf("%d ",a[i]);
            puts("");
        }
        if(!f) puts("-1");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp