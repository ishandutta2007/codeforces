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
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
char s[2][100005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,ans=0;
        scanf("%d",&n);
        scanf("%s",s[0]+1);
        scanf("%s",s[1]+1);
        int f0=0,f1=0;
        for(int i=1;i<=n;i++){
            int cnt=s[0][i]-'0'+s[1][i]-'0';
            if(cnt==2){
                f1=1;
                if(f0&&f1) ans+=2,f0=0,f1=0;
            }
            else if(cnt==1) f0=0,f1=0,ans+=2;
            else{
                f0=1;
                if(f0&&f1) ans+=2,f0=0,f1=0;
                else if(i==n||s[0][i+1]=='0'||s[1][i+1]=='0') ans++,f0=0;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
//
/// 
//01
//