#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
char s[105];
int a[105],b[105];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,ans=0,cnt=0;
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) cnt+=s[i]-'0';
        ans=cnt;
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
        for(int i=1;i<=1000;i++){
            for(int j=1;j<=n;j++){
                if(i>=b[j]&&(i-b[j])%a[j]==0){
                    if(s[j]=='0') s[j]='1',cnt++;
                    else s[j]='0',cnt--;
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp