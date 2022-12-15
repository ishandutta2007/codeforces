#pragma GCC optimize("Ofast,unroll-loops")
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
char s[200005],t[200005];
vector <pair<int,int>> v[2];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        scanf("%s",t+1);
        if(s[1]!=t[1]||s[n]!=t[n]){
            puts("-1");
            continue;
        }
        v[0].clear(),v[1].clear();
        int cnt=0;
        for(int i=1;i<=n+1;i++){
            if(i==n+1||s[i]=='0'){
                if(cnt) v[0].push_back(make_pair(i-cnt,i-1)),cnt=0;
            }
            else cnt++;
        }
        cnt=0;
        for(int i=1;i<=n+1;i++){
            if(i==n+1||t[i]=='0'){
                if(cnt) v[1].push_back(make_pair(i-cnt,i-1)),cnt=0;
            }
            else cnt++;
        }
        if(v[0].size()!=v[1].size()) puts("-1");
        else{
            long long ans=0;
            for(int i=0;i<v[0].size();i++) ans+=abs(v[0][i].first-v[1][i].first)+abs(v[0][i].second-v[1][i].second);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
//unordered_map
//cf