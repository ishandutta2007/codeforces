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
char s[55];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        scanf("%s",s+1);
        int f[26]={},ans=0;
        for(int i=1;i<=n;i++){
            ans++;
            if(!f[s[i]-'A']) f[s[i]-'A']=1,ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
//unordered_map
//cf