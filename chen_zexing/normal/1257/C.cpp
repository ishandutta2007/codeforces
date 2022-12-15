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
int a[200005];
vector <int> v[200005];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int mn=INT_MAX,n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),v[i].clear();
        for(int i=1;i<=n;i++) v[a[i]].push_back(i);
        for(int i=1;i<=n;i++)
            for(int j=1;j<v[i].size();j++)
                mn=min(mn,v[i][j]-v[i][j-1]+1);
        printf("%d\n",mn!=INT_MAX?mn:-1);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp