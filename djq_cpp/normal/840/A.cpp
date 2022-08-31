#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <utility>
#include <functional>
#include <bitset>
#include <cctype>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);i++)
#define rep1(i,n) for(int i=1;i<=int(n);i++)
typedef long long ll;
typedef pair<int,int> pii;
int a[200005],ra[200005];
pii b[200005];
int main(){
    int n;
    scanf("%d",&n);
    rep(k,n)scanf("%d",&a[k]);
    rep(k,n){
        scanf("%d",&b[k].first);
        b[k].second=k;
    }
    sort(a,a+n);
    sort(b,b+n);
    for(int k=n-1;k>=0;k--)
        ra[b[n-1-k].second]=a[k];
    rep(k,n)printf("%d ",ra[k]);
    return 0;
}