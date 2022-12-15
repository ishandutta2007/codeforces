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
char s[100005];
int f[26];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,t;
        cin>>n;
        scanf("%s",s+1);
        scanf("%d",&t);
        memset(f,0,sizeof(f));
        while(t--){
            char c='-';
            while(c<'a'||c>'z') scanf("%c",&c);
            f[c-'a']=1;
        }
        int ans=0,lst=0;
        for(int i=1;i<=n;i++){
            if(f[s[i]-'a']){
                if(!lst) ans=max(ans,i-1);
                else ans=max(ans,i-lst);
                lst=i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
//unordered_map