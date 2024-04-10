#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#pragma comment (linker,"/STACK:128000000")

using namespace std;

int arr[100005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    long long ans=0;//1LL*n*(n-2)*(n-3)/6;
    int r=0,cnt=0;
    for(int i=0;i<n;++i) {
        while(r<n&&arr[r]-arr[i]<=d) ++r,++cnt;
        ans+=1LL*(cnt-1)*(cnt-2)/2;
        --cnt;
    }
    cout << ans << endl;
    return 0;
}