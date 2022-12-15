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
char s[300005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,cnt=0;
        cin>>n;
        scanf("%s",s+1);
        int cntl=0,cntr=0;
        if(n%2){
            puts(":(");
            continue;
        }
        for(int i=1;i<=n;i++){
            if(s[i]=='(') cntl++;
            else if(s[i]==')') cntr++;
        }
        if(cntl>n/2||cntr>n/2){
            puts(":(");
            continue;
        }
        cntl=n/2-cntl,cntr=n/2-cntr;
        for(int i=1;i<=n;i++){
            if(s[i]=='?'){
                if(cntl) s[i]='(',cntl--;
                else s[i]=')';
            }
            if(s[i]=='(') cnt++;
            else cnt--;
            if(cnt<=0&&i!=n){
                puts(":(");
                exit(0);
            }
        }
        for(int i=1;i<=n;i++) printf("%c",s[i]);

    }
    return 0;
}
//
/// 
//01
//