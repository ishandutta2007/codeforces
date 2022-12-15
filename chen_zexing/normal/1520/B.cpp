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
char s[105];
int f[26];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        int len=0,temp=n;
        while(temp) temp/=10,len++;
        int ans=(len-1)*9;
        temp=1;
        int t=0,now=1,f=0;
        while(now<=len) t+=temp,temp*=10,now++;
        f=t;
        while(f<=n) ans++,f+=t;
        printf("%d\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp