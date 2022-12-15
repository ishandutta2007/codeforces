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
    //cin>>T;
    while(T--){
        scanf("%s",s);
        int len=strlen(s);
        int cnt=0;
        int l=0,r=len-1;
        vector <int> ans;
        while(l<r){
            while(l<r&&s[l]!='(') l++;
            while(r>l&&s[r]!=')') r--;
            if(l>=r||s[l]!='('||s[r]!=')') break;
            ans.push_back(l);
            ans.push_back(r);
            l++,r--;
        }
        if(ans.size()==0){
            puts("0");
            continue;
        }
        puts("1");
        printf("%d\n",ans.size());
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++) printf("%d ",ans[i]+1);
    }
    return 0;
}