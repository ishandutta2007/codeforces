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
int a[105],b[105];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
        int f=1;
        for(int i=1;i<=n;i++) if(a[i]<b[i]) f=0;
        for(int i=2;i<=n;i++) if(a[i]<a[i-1]||b[i]<b[i-1]||(b[i]-b[i-1])>a[i]-a[i-1]) f=0;
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}