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
int cnt[10];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=3;i++) cnt[i]=0;
        for(int i=1;i<=n;i++){
            int t;
            scanf("%d",&t);
            cnt[t]++;
        }
        cout<<cnt[1]+cnt[3]<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp