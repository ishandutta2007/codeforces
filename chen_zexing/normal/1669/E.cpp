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
char s[100005][3];
int cnt[2][26];
unordered_map <string,int> mp;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        memset(cnt,0,sizeof(cnt));
        mp.clear();
        long long ans=0;
        for(int i=1;i<=n;i++){
            scanf("%s",s[i]+1);
            ans+=cnt[0][s[i][1]-'a'],ans+=cnt[1][s[i][2]-'a'];
            cnt[0][s[i][1]-'a']++,cnt[1][s[i][2]-'a']++;
            string t="";
            t+=s[i][1],t+=s[i][2];
            ans-=mp[t]*2,mp[t]++;
            //cout<<ans<<endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//unordered_map