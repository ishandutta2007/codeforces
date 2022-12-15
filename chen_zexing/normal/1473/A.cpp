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
        int n,k,f=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]>k) f=1;
        }
        sort(a+1,a+n+1);
        if(f&&a[1]+a[2]>k) puts("NO");
        else puts("YES");
    }
    return 0;
}