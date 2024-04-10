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
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
vector <int> v;
void solve(int st,int ed){
    //cout<<st<<" "<<ed<<endl;
    if(st==ed){
        v.push_back(st);
        return;
    }
    v.push_back(st);
    for(int i=ed;i>st;i--){
        v.push_back(i);
        if(i!=st+1) v.push_back(st);
    }
    solve(st+1,ed);
    v.push_back(st);
}
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        solve(0,k-1);
        for(int i=0;i<n;i++){
            printf("%c",v[i%v.size()]+'a');
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp