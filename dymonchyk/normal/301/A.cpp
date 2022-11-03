#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>

using namespace std;

int arr[205];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<2*n-1;++i) {
        scanf("%d",&arr[i]);
        if (arr[i]<0) {
            arr[i]*=-1;
            ++cnt;
        }
    }
    cnt%=n; cnt=min(cnt%2,(n-cnt)%2);
    sort(arr,arr+2*n-1);
    int ans=0;
    for(int i=0;i<2*n-1;++i) {
        if (i<cnt) ans-=arr[i];
        else ans+=arr[i];
    }
    printf("%d\n",ans);
    return 0;
}