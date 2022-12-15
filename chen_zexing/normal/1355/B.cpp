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
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int cnt=0,ans=0;
        for(int i=1;i<=n;i++){
            cnt++;
            if(cnt>=a[i]){
                cnt=0;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}