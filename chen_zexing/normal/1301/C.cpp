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
long long a[100005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        int t=n-m;
        int v=t/(m+1),c2=t%(m+1);
        int c1=m+1-c2;
        long long ans=1LL*n*(n+1)/2;
        ans-=1LL*c1*v*(v+1)/2+1LL*c2*(v+1)*(v+2)/2;
        cout<<ans<<endl;
    }
    return 0;
}