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

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    long long p,q;
    cin >> p >> q;
    int n; long long arr[102];
    cin >> n;
    for(int i=0;i<n;++i)
        cin >> arr[i];
    for(int i=0;i<n;++i) {
        if (q==0||p/q!=arr[i]&&(i!=n-2||p/q-1!=arr[i]||arr[i+1]!=1)) {
            puts("NO");
            return 0;
        }
        p-=q*arr[i];
        if (q>p) swap(p,q);
    }
    if (q==0) puts("YES");
    else puts("NO");
//  cout << p << "  " << q << endl;
    return 0;
}