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
int a[100005],b[100005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,m,k;
        int ans;
        cin>>n>>m>>k;
        ans=n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i]-a[i-1]-1;
        sort(b+2,b+n+1);
        for(int i=2;i<=n-k+1;i++) ans+=b[i];
        cout<<ans<<endl;
    }
    return 0;
}