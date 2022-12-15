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
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
string s[1000005];
int f[1000005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m,q;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>s[i];
        for(int i=1;i<=m;i++) f[i]=0;
        for(int i=0;i<m-1;i++)
            for(int j=1;j<n;j++)
                if(s[j+1][i]=='X'&&s[j][i+1]=='X')
                    f[i+1]=1;
        for(int i=1;i<=m;i++) f[i]+=f[i-1];
        cin>>q;
        for(int i=1,l,r;i<=q;i++){
            cin>>l>>r;
            if(l==r) puts("YES");
            else{
                if(f[r-1]-f[l-1]==0) puts("YES");
                else puts("NO");
            }
        }
    }
    return 0;
}
//
/// 
//01
//