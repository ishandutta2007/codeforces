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
int a[100005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,x,ans=INT_MAX,f=0;
        cin>>n>>x;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]==x) f=1;
            ans=min(ans,x/a[i]+(x%a[i]>0));
        }
        if(f) printf("%d\n",ans);
        else printf("%d\n",max(ans,2));
    }
    return 0;
}
//
/// 
//01
// 
//
//dp