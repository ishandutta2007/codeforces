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
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        vector <int> v;
        int ans=0;
        for(int i=n;i>k;i--) v.push_back(i),ans++;
        for(int i=k-1;i>=(k+1)/2;i--) v.push_back(i),ans++;
        printf("%d\n",ans);
        if(ans) for(int i=0;i<ans;i++) printf("%d ",v[i]);
        puts("");
    }
    return 0;
}
//
/// 