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
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int a[200005],cnt[200005];
vector <int> v[2];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
        for(int i=1;i<=n;i++)
            if(cnt[a[i]]>2){
                puts("NO");
                exit(0);
            }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            if(i!=1&&a[i]==a[i-1]) v[1].push_back(a[i]);
            else v[0].push_back(a[i]);
        }
        sort(v[0].begin(),v[0].end());
        sort(v[1].begin(),v[1].end());
        puts("YES");
        printf("%d\n",v[0].size());
        for(int i=0;i<v[0].size();i++) printf("%d ",v[0][i]);
        puts("");
        printf("%d\n",v[1].size());
        for(int i=v[1].size()-1;i>=0;i--) printf("%d ",v[1][i]);
        puts("");
    }
    return 0;
}
//
/// 
//01
//