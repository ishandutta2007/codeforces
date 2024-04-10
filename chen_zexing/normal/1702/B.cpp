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
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        scanf("%s",s+1);
        int n=strlen(s+1),f[26]={},cnt=0,ans=0;
        for(int i=1;i<=n;i++){
            if(cnt==3&&!f[s[i]-'a']){
                memset(f,0,sizeof(f));
                cnt=1;
                f[s[i]-'a']=1;
                ans++;
            }
            else{
                if(!f[s[i]-'a']) f[s[i]-'a']=1,cnt++;
            }
        }
        if(cnt) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
//unordered_map