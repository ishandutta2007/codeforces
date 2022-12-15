#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int a[55];
struct answer{
    int x,y,z;
};
vector <answer> ans;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        ans.clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<n;i++){
            int mn=INT_MAX,pos=-1;
            for(int j=i;j<=n;j++) if(a[j]<mn) mn=a[j],pos=j;
            if(pos==i) continue;
            ans.push_back(answer{i,pos,pos-i});
            for(int j=pos;j>i;j--) a[j]=a[j-1];
        }
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++) printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);
    }
    return 0;
}
//
/// 
//01
//