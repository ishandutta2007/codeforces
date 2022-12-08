#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
const int MAXN = 1e6 + 7;
int p[30][MAXN],cnt[30],c[30];
int n,m;
char str[MAXN], s[MAXN];
signed main(){
    scanf("%lld",&n);scanf("%s",str+1);
    for (int i=1;i<=n;++i) p[str[i]-'a'][++cnt[str[i]-'a']]=i;
    scanf("%lld",&m);
    for (int i=1;i<=m;++i){
        scanf("%s",s+1);
        for (int j=0;j<=25;++j)c [j] = 0;
        int len=strlen(s+1);
        for (int j=1;j<=len;++j)c[s[j]-'a']++;
        int ans = 1;
        for (int j=0;j<=25;++j) ans = max(ans,p[j][c[j]]);
        printf("%lld\n",ans);
    }
    return 0;
}