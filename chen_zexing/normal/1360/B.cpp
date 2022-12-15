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
int a[105];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=INT_MAX;
        sort(a+1,a+n+1);
        for(int i=1;i<n;i++) ans=min(ans,a[i+1]-a[i]);
        cout<<ans<<endl;
    }
    return 0;
}