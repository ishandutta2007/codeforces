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
        scanf("%s",s+1);
        memset(f,0,sizeof(f));
        int fl=1;
        for(int i=1;i<=n;i++){
            if(s[i]==s[i-1]) continue;
            if(f[s[i]-'A']) fl=0;
            f[s[i]-'A']=1;
        }
        puts(fl?"YES":"NO");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp