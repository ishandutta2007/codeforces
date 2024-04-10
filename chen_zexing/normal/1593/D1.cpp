#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int a[100005];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main() {
    int T = 1;
    cin >> T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        if(a[1]==a[n]){
            puts("-1");
            continue;
        }
        int g=a[2]-a[1];
        for(int i=2;i<n;i++) g=gcd(g,a[i+1]-a[i]);
        printf("%d\n",g);
    }
    return 0;
}
//
/// 
//01
//