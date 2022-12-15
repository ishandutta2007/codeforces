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
#define li __int128_t
using namespace std;
char s[105];
int main() {
    int T = 1;
    cin >> T;
    while (T--){
        int n,f=0;
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            if(s[i]=='R'||s[i]=='B'){
                if(!f) f=i;
                for(int j=i+1;j<=n&&s[j]=='?';j++){
                    if(s[j-1]=='B') s[j]='R';
                    else s[j]='B';
                }
            }
        }
        if(f){
            for(int j=f-1;j>=1;j--){
                if(s[j+1]=='B') s[j]='R';
                else s[j]='B';
            }
        }
        else for(int j=1;j<=n;j++) s[j]=j%2?'R':'B';
        for(int i=1;i<=n;i++) printf("%c",s[i]);
        puts("");
    }
    return 0;
}
//
/// 
//01
//
//!