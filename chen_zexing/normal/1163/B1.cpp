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
int cnt[100005],ccnt[100005],a[100005];
set <int> s;
int check(){
    if(s.size()==1) return *s.begin()==1||ccnt[*s.begin()]==1;
    else if(s.size()==2){
        auto it=s.begin();
        if(*s.begin()==1&&ccnt[1]==1) return 1;
        ++it;
        if(*it!=*s.begin()+1) return 0;
        if(ccnt[*it]!=1) return 0;
        return 1;
    }
    else return 0;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,ans=1;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            if(cnt[a[i]]){
                ccnt[cnt[a[i]]]--;
                if(ccnt[cnt[a[i]]]==0) s.erase(s.find(cnt[a[i]]));
            }
            cnt[a[i]]++,ccnt[cnt[a[i]]]++;
            if(ccnt[cnt[a[i]]]==1) s.insert(cnt[a[i]]);
            if(check()) ans=i;
        }
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
//