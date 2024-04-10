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
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
char s[1000005];
int a[1000005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,x=0;
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) if(s[i]=='*') a[++x]=i;
        int pos=a[x/2+1];
        long long ans=0;
        for(int i=1;i<=x;i++){
            int temp;
            temp=i<=x/2+1?pos-(x/2+1-i):pos+(i-x/2-1);
            ans+=abs(a[i]-temp);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp