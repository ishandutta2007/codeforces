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
char s[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,x,y,cnt=0;
        cin>>n>>x>>y;
        scanf("%s",s);
        for(int i=0;i<n/2;i++) swap(s[i],s[n-i-1]);
        for(int i=0;i<x;i++) if(s[i]=='1'&&i!=y||s[i]=='0'&&i==y) cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}
//
/// 
//01
//