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
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
char s[55];
int ans[55][55];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,cnt=0;
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) if(s[i]=='2') cnt++;
        if(cnt==0){
            puts("YES");
            for(int i=1;i<=n;i++,puts(""))
                for(int j=1;j<=n;j++){
                    if(i==j) printf("X");
                    else printf("=");
                }
        }
        else if(cnt==1||cnt==2) puts("NO");
        else{
            puts("YES");
            vector <int> v;
            for(int i=1;i<=n;i++) if(s[i]=='2') v.push_back(i);
            memset(ans,0,sizeof(ans));
            for(int i=0;i<v.size();i++) ans[v[i]][v[(i+1)%v.size()]]=1,ans[v[(i+1)%v.size()]][v[i]]=-1;
            for(int i=1;i<=n;i++,puts(""))
                for(int j=1;j<=n;j++){
                    if(ans[i][j]==1) printf("+");
                    else if(ans[i][j]==-1) printf("-");
                    else if(i==j) printf("X");
                    else printf("=");
                }
        }
    }
    return 0;
}
//
/// 
//01
//