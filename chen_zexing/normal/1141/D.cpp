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
char l[150005],r[150005];
vector <int> v[27][2];
struct answer{
    int x,y;
}ans[150005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,x=0;
        cin>>n;
        scanf("%s",l+1),scanf("%s",r+1);
        for(int i=1;i<=n;i++){
            if(l[i]>='a'&&l[i]<='z') v[l[i]-'a'][0].push_back(i);
            else v[26][0].push_back(i);
            if(r[i]>='a'&&r[i]<='z') v[r[i]-'a'][1].push_back(i);
            else v[26][1].push_back(i);
        }
        for(int i=0;i<26;i++){
            while(v[i][0].size()&&v[i][1].size()) ans[++x]=answer{v[i][0].back(),v[i][1].back()},v[i][0].pop_back(),v[i][1].pop_back();
        }
        while(v[26][0].size()){
            for(int i=0;i<=26;i++) if(v[i][1].size()){
                    ans[++x]=answer{v[26][0].back(),v[i][1].back()},v[26][0].pop_back(),v[i][1].pop_back();
                    break;
                }
        }
        while(v[26][1].size()){
            for(int i=0;i<=26;i++) if(v[i][0].size()){
                    ans[++x]=answer{v[i][0].back(),v[26][1].back()},v[i][0].pop_back(),v[26][1].pop_back();
                    break;
                }
        }
        printf("%d\n",x);
        for(int i=1;i<=x;i++) printf("%d %d\n",ans[i].x,ans[i].y);
    }
    return 0;
}
//
/// 
//01
//