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
char s[1005];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        scanf("%s",s+1);
        int ans=n;
        for(int i=1;i<=n;i++){
            if(s[i]=='0') continue;
            ans=max(ans,i*2);
            ans=max(ans,(n-i+1)*2);
        }
        cout<<ans<<endl;
    }
    return 0;
}