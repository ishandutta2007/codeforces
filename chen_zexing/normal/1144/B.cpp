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
int a[2005];
vector <int> v[2];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1,t;i<=n;i++) cin>>t,v[t%2].push_back(t);
        if(max(v[0].size(),v[1].size())-min(v[0].size(),v[1].size())<=1) puts("0");
        else{
            if(v[0].size()>v[1].size()){
                sort(v[0].begin(),v[0].end());
                long long ans=0;
                for(int i=0;i<v[0].size()-v[1].size()-1;i++) ans+=v[0][i];
                cout<<ans<<endl;
            }
            else{
                sort(v[1].begin(),v[1].end());
                long long ans=0;
                for(int i=0;i<v[1].size()-v[0].size()-1;i++) ans+=v[1][i];
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
//
/// 
//01
//