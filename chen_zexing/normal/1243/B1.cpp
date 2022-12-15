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
char s[10005],t[10005];
int p[10005];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n,x=0;
        cin>>n;
        scanf("%s",s+1);
        scanf("%s",t+1);
        for(int i=1;i<=n;i++) if(s[i]!=t[i]) p[++x]=i;
        if(x==2&&s[p[1]]==s[p[2]]&&t[p[2]]==t[p[1]]) puts("Yes");
        else puts("No");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp