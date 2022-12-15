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
int a[105],f[1000005];
int sum=0;
int check(int n){
    int f=0,s=0;
    for(int i=1;i<=n;i++) s+=a[i];
    if(s%2) return -1;
    for(int i=1;i<=n;i++)
        if(a[i]%2)
            return i;
    return 0;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) sum+=a[i];
        if(sum%2){
            puts("0");
            continue;
        }
        while(!check(n)){
            for(int i=1;i<=n;i++) a[i]/=2;
        }
        if(check(n)==-1){
            puts("0");
            return 0;
        }
        f[0]=1;
        int s=0;
        for(int i=1;i<=n;i++) s+=a[i];
        for(int i=1;i<=n;i++){
            for(int j=s/2-a[i];j>=0;j--)
                if(f[j]) f[j+a[i]]=1;
        }
        if(!f[s/2]) printf("0\n");
        else printf("1\n%d\n",check(n));
    }
    return 0;
}
//
/// 
//01
// 
//
//dp