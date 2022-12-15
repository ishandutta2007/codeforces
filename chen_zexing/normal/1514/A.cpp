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
    while(T--) {
        int n,f=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(int(sqrt(a[i]))*int(sqrt(a[i]))!=a[i]) f=1;
        }
        puts(f?"YES":"NO");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp