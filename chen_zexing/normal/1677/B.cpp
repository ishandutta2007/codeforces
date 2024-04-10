#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
int f[1000005];
int ans[1000005];
char s[1000005];
int fl[1000005],ac[1000005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,m,cnt=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++) f[i]=0;
        for(int i=0;i<n*m;i++) fl[i]=0;
        for(int i=1;i<=n*m;i++) ans[i]=ac[i]=0;
        scanf("%s",s+1);
        for(int i=1,t;i<=n*m;i++){
            t=s[i]-'0';
            if(t&&!f[i%m]) f[i%m]=1,cnt++;
            ans[i]+=cnt;
        }
        int last=-1;
        for(int i=0,t;i<n*m;i++){
            t=s[i+1]-'0';
            if(last!=-1&&i-last<m||t) fl[i]=1;
            if(t) last=i;
            if(i>=m) ac[i]=fl[i]+ac[i-m];
            else ac[i]=fl[i];
            ans[i+1]+=ac[i];
            //cout<<i<<" "<<ac[i]<<endl;
        }
        for(int i=1;i<=n*m;i++) printf("%d%c",ans[i],i==n*m?'\n':' ');
    }
    return 0;
}
//unordered_map