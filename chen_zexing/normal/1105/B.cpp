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
char s[200005];

int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        scanf("%s",s+1);
        int ans=0;
        for(int i=0;i<26;i++){
            int cnt=0,temp=0;
            for(int j=1;j<=n;j++){
                if(s[j]=='a'+i) {
                    temp++;
                    if (temp >= k) {
                        temp -= k;
                        cnt++;
                    }
                }
                else temp=0;
            }
            ans=max(ans,cnt);
        }
        cout<<ans<<endl;
    }
    return 0;
}