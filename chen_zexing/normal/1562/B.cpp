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
char s[55];
int f[15],cnt[15];
int prime(int x){
    for(int i=2;i*i<=x;i++) if(x%i==0) return 1;
    return 0;
}
int main() {
    f[1]=f[4]=f[6]=f[8]=f[9]=1;
    int T = 1;
    cin >> T;
    while (T--) {
        int n,fl=0;
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) if(f[s[i]-'0']) fl=s[i]-'0';
        if(fl){
            printf("1\n%d\n",fl);
            continue;
        }
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++) cnt[s[i]-'0']++;
        for(int i=1;i<=9;i++) if(cnt[i]>=2){
                printf("2\n%d\n",i*10+i);
                fl=1;
                break;
            }
        if(fl) continue;
        int mn=10,ans=0;
        for(int i=1;i<(1<<n);i++){
            int c=0,v=0;
            for(int j=1;j<=n;j++) if((1<<(j-1))&i) v=v*10+s[j]-'0',c++;
            if(prime(v)&&c<mn) mn=c,ans=v;
        }
        printf("%d\n%d\n",mn,ans);
    }
    return 0;
}
//
/// 
//01
//