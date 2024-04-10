#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

int arr[2000004];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    reverse(arr,arr+n);
    long long ans=0,mn=1,cnt=0;
    int nn=n;
    while(nn>0) {
        ++cnt;
        nn/=4;
    }
    int cur=0;
    while(cur<n) {
        for(int i=0;i<mn;++i)
            ans+=arr[cur+i]*cnt;
        cur+=mn;
        if (mn==1) mn*=3;
        else mn*=4;
        cnt--;
    }
    cout << ans << endl;
    return 0;
}