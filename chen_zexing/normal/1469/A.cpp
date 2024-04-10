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
int main() {
    int T;
    cin>>T;
    while(T--){
        char s[105];
        scanf("%s",s);
        int l=strlen(s);
        int cnt=0;
        if(s[0]==')'||s[l-1]=='('||l%2) puts("NO");
        else puts("YES");
    }
    return 0;
}