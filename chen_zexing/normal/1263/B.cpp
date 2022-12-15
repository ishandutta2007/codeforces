#include <stdio.h>
#include <iostream>
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
unordered_map<string ,int> mp,mp2;
int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        string s[15];
        cin>>n;
        int ans=0;
        mp2.clear();
        mp.clear();
        for(int i=1;i<=n;i++) cin>>s[i],mp2[s[i]]++,mp[s[i]]=1;
        for(int i=1;i<=n;i++){
            if(mp2[s[i]]>1) {
                mp2[s[i]]--;
                for(int j=0;j<=9;j++)
                {
                    s[i][3]='0'+j;
                    if(!mp[s[i]]){
                        ans++;
                        mp[s[i]]=1;
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=n;i++) cout<<s[i]<<endl;
    }
    return 0;
}