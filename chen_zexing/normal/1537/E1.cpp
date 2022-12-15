#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
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
using namespace std;
char s[5005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        scanf("%s",s+1);
        string a[5005];
        for(int i=1;i<=n;i++) {
            a[i]="";
            for (int j = 1; j <= k; j++) a[i]+=s[(j-1)%i+1];
        }
        string ans=a[1];
        for(int i=2;i<=n;i++){
            for(int j=0;j<k;j++){
                if(ans[j]>a[i][j]){
                    ans=a[i];
                    break;
                }
                else if(ans[j]<a[i][j]) break;
            }
        }
        for(int i=0;i<k;i++) printf("%c",ans[i%ans.size()]);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp