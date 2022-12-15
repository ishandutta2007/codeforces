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
unordered_map<int,int> mp;
int a[100005],b[100005];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        mp.clear();
        int n,f=1;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++){
            if(a[i]<b[i]&&mp[1]==0) f=0;
            if(a[i]>b[i]&&mp[-1]==0)  f=0;
            mp[a[i]]=1;
        }
        puts(f?"YES":"NO");
    }
    return 0;
}
//
/// 
//01
// 
//