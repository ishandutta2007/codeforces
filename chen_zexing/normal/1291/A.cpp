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
char s[3005];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        scanf("%s",s+1);
        vector <int> v;
        int f=0;
        for(int i=1;i<=n;i++) if((s[i]-'0')%2) v.push_back((s[i]-'0')),f=1;
        if(!f||v.size()<2) puts("-1");
        else printf("%d%d\n",v[0],v[1]);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp