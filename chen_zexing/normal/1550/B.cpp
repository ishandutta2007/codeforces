#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
using namespace std;
char s[105];
int main() {
    int T = 1;
    cin >> T;
    while (T--){
        int n,a,b;
        cin>>n>>a>>b;
        scanf("%s",s+1);
        if(b>=0) printf("%d\n",b*n+a*n);
        else{
            int cnt[2]={};
            for(int i=1;i<=n;i++) if(i==1||s[i]!=s[i-1]) cnt[s[i]-'0']++;
            printf("%d\n",(min(cnt[0],cnt[1])+1)*b+a*n);
        }
    }
    return 0;
}