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
char s[5005];
int n, sa[5005], rk[10010], oldrk[10010],ht[5005],st[5005][16],w;
void get_sa_and_height() {
    memset(rk,0,sizeof(rk));
    int i, p, k;
    for (i = 1; i <= n; ++i) sa[i] = i, rk[i] = s[i];
    for (w = 1; w < n; w <<= 1) {
        sort(sa + 1, sa + n + 1, [](int x, int y) {
            return rk[x] == rk[y] ? rk[x + w] < rk[y + w] : rk[x] < rk[y];
        });
        memcpy(oldrk, rk, sizeof(rk));
        for (p = 0, i = 1; i <= n; ++i) {
            if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&
                oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]) {
                rk[sa[i]] = p;
            } else {
                rk[sa[i]] = ++p;
            }
        }
    }
    for (i = 1, k = 0; i <= n; ++i) {
        if (k) --k;
        while (s[i + k] == s[sa[rk[i]-1] + k]) ++k;
        ht[rk[i]] = k;
    }
    for(i=1;i<=n;i++) st[i][0]=ht[i];
    for(i=1;i<16;i++)
        for(int j=1;j<=n;j++)
            st[j][i]=min(st[j][i-1],st[min(j+(1<<(i-1)),n)][i-1]);
}
int lcp(int a,int b){
    a=rk[a]+1,b=rk[b];
    int lg=log2(b-a+1);
    return min(st[a][lg],st[b-(1<<lg)+1][lg]);
}
int ans[5005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int aans=0;
        cin>>n;
        scanf("%s",s+1);
        get_sa_and_height();
        //for(int i=1;i<=n;i++) cout<<sa[i]<<" ";puts("");
        //for(int i=1;i<=n;i++) cout<<rk[i]<<" ";puts("");
        //for(int i=1;i<=n;i++) cout<<ht[i]<<" ";puts("");
        for(int i=1;i<=n;i++){
            ans[i]=n-i+1;
            for(int j=1;j<i;j++)
                if(rk[j]<rk[i])
                    ans[i]=max(ans[i],ans[j]+n-i+1-lcp(j,i));
            aans=max(aans,ans[i]);
            //cout<<ans[i]<<" ";
        }
        //puts("");
        printf("%d\n",aans);
    }
    return 0;
}
//
/// 
//01
//