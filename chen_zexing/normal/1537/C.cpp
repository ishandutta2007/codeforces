#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
using namespace std;
int a[200005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int mn=INT_MAX,pos=-1;
        for(int i=2;i<=n;i++) if(mn>a[i]-a[i-1]) mn=a[i]-a[i-1],pos=i-1;
        printf("%d ",a[pos]);
        for(int i=pos+2;i<=n;i++) printf("%d ",a[i]);
        for(int i=1;i<pos;i++) printf("%d ",a[i]);
        printf("%d\n",a[pos+1]);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp