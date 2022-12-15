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
int n,m;
struct node{
    string s;
    int id;
    friend bool operator <(node a,node b){
        return a.s<b.s;
    }
}a[1000005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) {
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i].s,a[i].id=i;
        for(int i=1;i<=n;i++) for(int j=0;j<m;j++) if(j%2) a[i].s[j]=25-(a[i].s[j]-'a')+'a';
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) cout<<a[i].id<<" ";
        puts("");
    }
    return 0;
}
//
/// 
//01
//