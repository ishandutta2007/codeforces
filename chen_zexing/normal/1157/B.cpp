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
int f[10];
char s[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,fl=0;
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<=9;i++) scanf("%d",&f[i]);
        for(int i=1;i<=n;i++){
            if(f[s[i]-'0']>s[i]-'0'){
                if(fl==0) fl=1,printf("%d",f[s[i]-'0']);
                else if(fl==1) printf("%d",f[s[i]-'0']);
                else printf("%d",s[i]-'0');
            }
            else if(f[s[i]-'0']==s[i]-'0') printf("%d",f[s[i]-'0']);
            else{
                if(!fl) printf("%d",s[i]-'0');
                else if(fl==1) fl=2,printf("%d",s[i]-'0');
                else printf("%d",s[i]-'0');
            }
        }
    }
    return 0;
}
//
/// 
//01
//