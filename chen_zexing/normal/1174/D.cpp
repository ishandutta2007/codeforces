#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
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
using namespace std;
set <int> s;
int main() {
    int T = 1;
    //cin >> T;
    while (T--){
        int n,x;
        cin>>n>>x;
        vector <int> v;
        v.push_back(0);
        for(int i=0;i<(1<<n);i++) s.insert(i);
        s.erase(s.find(0));
        if(x<(1<<n)) s.erase(s.find(x));
        while(s.size()){
            int t=*s.begin();
            v.push_back(t);
            s.erase(s.find(t));
            if(s.find(t^x)!=s.end()) s.erase(s.find(t^x));
        }
        printf("%d\n",v.size()-1);
        for(int i=1;i<v.size();i++) printf("%d ",v[i]^v[i-1]);
    }
    return 0;
}
//
/// 
//01
//
//!