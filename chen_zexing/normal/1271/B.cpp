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
vector <int> ans;
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        scanf("%s",s+1);
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++) s[i]=='B'?cnt1++:cnt2++;
        if(cnt1%2&&cnt2%2){
            puts("-1");
            continue;
        }
        if(cnt1%2) {
            for (int i = 1; i < n; i++){
                if(s[i]=='W') {
                    ans.push_back(i);
                    if (s[i + 1] == 'B') s[i + 1] = 'W';
                    else s[i + 1] = 'B';
                }
            }
        }
        else{
            for(int i=1;i<n;i++){
                if(s[i]=='B') {
                    ans.push_back(i);
                    if (s[i + 1] == 'B') s[i + 1] = 'W';
                    else s[i + 1] = 'B';
                }
            }
        }
        printf("%d ",ans.size());
        for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
    }
    return 0;
}