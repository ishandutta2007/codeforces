#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

int arr[100005];

int main() {
//  freopen("input.txt","r", stdin);
//  freopen("output.txt", "w", stdout);
    int n,k,m,a;
    scanf("%d",&n);
    scanf("%d",&k);
    for(int i=1;i<n;++i) {
        scanf("%d",&a);
        k=min(k,a);
    }
    scanf("%d",&m);
    for(int i=0;i<m;++i)
        scanf("%d",&arr[i]);
    sort(arr,arr+m);
    reverse(arr,arr+m);
    int ans=0,left=k;
    for(int i=0;i<m;++i) {
        if (left==0) {
            left=k;
            i++;
        } else left--,ans+=arr[i];
    }
    printf("%d\n",ans);
    return 0;
}