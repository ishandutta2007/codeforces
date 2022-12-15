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
char s[205];
int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        scanf("%s",s+1);
        int f=0;
        if(s[1]=='2'&&s[2]=='0'&&s[3]=='2'&&s[4]=='0') f=1;
        if(s[1]=='2'&&s[2]=='0'&&s[3]=='2'&&s[n]=='0') f=1;
        if(s[1]=='2'&&s[2]=='0'&&s[n-1]=='2'&&s[n]=='0') f=1;
        if(s[1]=='2'&&s[n-2]=='0'&&s[n-1]=='2'&&s[n]=='0') f=1;
        if(s[n-3]=='2'&&s[n-2]=='0'&&s[n-1]=='2'&&s[n]=='0') f=1;
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}