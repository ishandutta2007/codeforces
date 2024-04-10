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
int a[105];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int tot=0;
        for(int i=1;i<=n;i++){
            int mx=a[i];
            for(int j=i+1;j<=n;j++) mx=max(mx,a[j]);
            tot+=mx-a[i];
        }
        if(k>tot){
            puts("-1");
            continue;
        }
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                if(a[j]<a[j+1]){
                    a[j]++;
                    if(i==k) printf("%d\n",j);
                    break;
                }
            }
        }
    }
    return 0;
}