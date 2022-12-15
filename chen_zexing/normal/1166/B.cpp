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
#include <functional>
#define hash hassh
using namespace std;
vector <char> v;
char c[5]={'a','e','i','o','u'};
void solve(int n,int m){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++) v.push_back(c[(j+i)%5]);
        for(int j=6;j<=m;j++) v.push_back(c[i-1]);
    }
    for(int i=6;i<=n;i++){
        for(int j=0;j<5;j++) v.push_back(c[j]);
        for(int j=6;j<=m;j++) v.push_back('a');
    }
    for(int i=0;i<v.size();i++) printf("%c",v[i]);
    puts("");
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int k,f=0;
        cin>>k;
        for(int i=1;i<=k;i++)
            if(k%i==0&&k/i>=5&&i>=5){
                f=1;
                solve(i,k/i);
                break;
            }
        if(!f) puts("-1");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp