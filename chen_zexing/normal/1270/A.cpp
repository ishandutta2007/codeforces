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
    int T;
    cin>>T;
    while(T--){
        int n,k1,k2;
        cin>>n>>k1>>k2;
        for(int i=1;i<=k1;i++) scanf("%d",&a[i]);
        for(int i=1;i<=k2;i++) scanf("%d",&b[i]);
        int f=0;
        for(int i=1;i<=k1;i++) if(a[i]==n) f=1;
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}