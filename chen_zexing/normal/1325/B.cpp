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
unordered_map <int,int> mp;
int a[100005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,ans=0;
        scanf("%d",&n);
        mp.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(!mp[a[i]]) ans++;
            mp[a[i]]=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}