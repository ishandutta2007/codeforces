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
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        int cnt=0;
        for(int i=1;i<=n;i++) cnt+=s[i]-'0',f[i]=0;
        if(cnt%2||cnt==0){
            puts("NO");
            continue;
        }
        else puts("YES");
        int pos=-1;
        for(int i=1;i<=n;i++) if(s[i]=='1'){
                pos=i;
                break;
            }
        pos++;
        if(pos>n) pos-=n;
        int now=pos+1;
        if(now>n) now-=n;
        int pre=0;
        while(now!=pos){
            if(!pre){
                printf("%d %d\n",pos,now);
                if(s[now]=='0') pre=now;
            }
            else{
                printf("%d %d\n",pre,now);
                if(s[now]=='1') pre=0;
                else pre=now;
            }
            now++;
            if(now>n) now-=n;
        }
    }
    return 0;
}