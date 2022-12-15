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
char s[55][55];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                if(s[i][j]=='.'){
                    if(j==1||j==n||i+2>n){
                        puts("NO");
                        exit(0);
                    }
                    s[i][j]='#';
                    if(s[i+1][j]=='#'||s[i+1][j-1]=='#'||s[i+1][j+1]=='#'||s[i+2][j]=='#'){
                        puts("NO");
                        exit(0);
                    }
                    s[i+1][j]=s[i+1][j-1]=s[i+1][j+1]=s[i+2][j]='#';
                }
        }
        puts("YES");
    }
    return 0;
}
//
/// 
//01
//