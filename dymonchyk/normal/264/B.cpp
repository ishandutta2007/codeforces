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
int ans[100005];

int main() {
//  freopen("input.txt","r", stdin);
//  freopen("output.txt", "w", stdout);
    int n,ret=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    for(int i=0;i<n;++i) {
        int a=0;
        for(int j=1;j*j<=arr[i];++j)
            if (arr[i]%j==0) {
                a=max(a,max(j==1 ? 0 : ans[j],ans[arr[i]/j]));
            }
        ++a;
        for(int j=1;j*j<=arr[i];++j)
            if (arr[i]%j==0) {
                ans[j]=max(a,ans[j]);
                ans[arr[i]/j]=max(ans[arr[i]/j],a);
            }
        ret=max(ret,a);
    }
    printf("%d\n",ret);
//  for(int i=1;i<=100000;++i)
//      printf("%d ",i);
    return 0;
}