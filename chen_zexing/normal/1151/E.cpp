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
using namespace std;
int a[100005],n;
int main() {
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]>a[i-1])
            ans+=1LL*(a[i]-a[i-1])*(n-a[i]+1);
        else
            ans+=1LL*a[i]*(a[i-1]-a[i]);
    }
    cout<<ans<<endl;
    return 0;
}