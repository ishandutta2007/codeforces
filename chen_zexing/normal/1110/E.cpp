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
long long a[100005],b[100005];
long long aa[100005],bb[100005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
        for(int i=1;i<n;i++) aa[i]=a[i+1]-a[i],bb[i]=b[i+1]-b[i];
        sort(aa+1,aa+n);
        sort(bb+1,bb+n);
        int f=1;
        for(int i=1;i<n;i++) if(aa[i]!=bb[i]) f=0;
        if(f&&a[1]==b[1]) puts("Yes");
        else puts("No");
    }
    return 0;
}