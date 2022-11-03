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
#include <queue>
#include <memory.h>

using namespace std;

int arr[200005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%d",&arr[i]);
    long long sum=0;
    int in=0,left=n;
    for(int i=1;i<=n;++i) {
        long long d=sum-1LL*(left-1-in)*arr[i]*in;
        if (d<k) {
            printf("%d\n",i);
            --left;
        }
        else {
            sum+=1LL*in*arr[i];
            ++in;
        }
    }
    return 0;
}