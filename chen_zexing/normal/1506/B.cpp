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
char s[55];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        scanf("%s",s+1);
        vector <int> v;
        for(int i=1;i<=n;i++)
            if(s[i]=='*')
                v.push_back(i);
        int lst=v[0],ans=1;
        for(int i=1;i<v.size();i++)
            if(v[i]-lst>k){
                lst=v[i-1];
                ans++;
            }
        if(v.size()!=1) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp