#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <map>

using namespace std;

int arr[100005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);
    int l=0,r=n-1;
    while(l+1<n) {
        if (arr[l]>arr[l+1]) break;
        ++l;
    }
    while(l>0&&arr[l-1]==arr[l]) --l;
    while(r>0) {
        if (arr[r]<arr[r-1]) break;
        --r;
    }
    while(r<n-1&&arr[r]==arr[r+1]) ++r;
    if (l<r) swap(arr[l],arr[r]);
    bool ok=true;
    for(int i=1;i<n;++i)
        if (arr[i-1]>arr[i]) ok=false;
    puts(ok ? "YES" : "NO");
    return 0;
}