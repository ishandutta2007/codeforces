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
char s[200005];
int f[200005];
set <int> st[27];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        scanf("%s",s+1);
        int n=strlen(s+1),k,now=0;
        scanf("%d",&k);
        for(int i=1;i<=26;i++) st[i].clear();
        for(int i=1;i<=n;i++) st[s[i]-'a'+1].insert(i),now+=s[i]-'a'+1,f[i]=1;
        while(now>k){
            for(int i=26;i;i--){
                if(st[i].size()){
                    f[*st[i].begin()]=0;
                    st[i].erase(st[i].begin());
                    now-=i;
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++) if(f[i]) printf("%c",s[i]);
        puts("");
    }
    return 0;
}
//unordered_map