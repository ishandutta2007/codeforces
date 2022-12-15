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
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[500005],cnt[500005];
vector <int> v[500005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,c,ans=0;
        cin>>n>>c;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[i]=cnt[i-1]+(a[i]==c),v[a[i]].push_back(i);
        for(int i=1;i<=500000;i++){
            if(i==c||v[i].size()==0) continue;
            int temp=1;
            ans=max(ans,temp);
            for(int j=1;j<v[i].size();j++){
                temp-=cnt[v[i][j]]-cnt[v[i][j-1]];
                temp++;
                ans=max(ans,temp);
                if(temp<1) temp=1;
            }
        }
        printf("%d\n",ans+cnt[n]);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp