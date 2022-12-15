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
int a[200005],b[200005];
char s[200005],t[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) a[i]=s[n-i+1]-'a';
        scanf("%s",t+1);
        for(int i=1;i<=n;i++) b[i]=t[n-i+1]-'a';
        for(int i=1;i<=n+1;i++){
            a[i]+=b[i];
            if(a[i]>=26) a[i]-=26,a[i+1]++;
        }
        for(int i=n+1;i>=1;i--){
            if(a[i]%2) a[i-1]+=26;
            a[i]/=2;
        }
        for(int i=n;i>=1;i--) printf("%c",a[i]+'a');
    }
    return 0;
}
//
/// 
//01
//