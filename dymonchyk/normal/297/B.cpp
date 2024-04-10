#include <cstring>
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

using namespace std;

vector < pair <int,int> > v;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,k,a;
    scanf("%d%d%d",&n,&m,&k);
    v.reserve(n+m);
    for(int i=0;i<n;++i) {
        scanf("%d",&a);
        v.push_back(make_pair(a,0));
    }
    for(int i=0;i<m;++i) {
        scanf("%d",&a);
        v.push_back(make_pair(a,1));
    }
    sort(v.rbegin(),v.rend());
    int cnt[2]={0};
    for(int i=0;i<v.size();) {
        int cur=v[i].first;
        while(i<v.size()&&v[i].first==cur) cnt[v[i].second]++,i++;
        if (cnt[0]>cnt[1]) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}