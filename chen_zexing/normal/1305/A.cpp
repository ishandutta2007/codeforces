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
int a[1005],b[1005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        puts("");
        for(int i=1;i<=n;i++) printf("%d ",b[i]);
        puts("");
    }
    return 0;
}