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

int mod=1000000007;
bool ok[1000006];
int pw2[1000006];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,k,a,b,l=100000000,r=-1,cnt=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;++i) {
        scanf("%d%d",&a,&b);
        if (b-a==k+1) {
            l=min(l,a);
            r=max(r,a);
            ++cnt; ok[l]=true;
        } else if (b-a!=1) {
            puts("0");
            return 0;
        }
    }
    int ans=(r-l<=k&&cnt==0); pw2[0]=1;
    for(int i=1;i<=n;i++)
        pw2[i]=2*pw2[i-1]%mod;
    for(int i=1;i<=l&&i<=n;++i) {
        if (i+k>=r) {
            int cur=min(k,n-k-1-i)-cnt+ok[i];
            if (cur<0) break;
            cur=pw2[cur];
            ans+=cur;
            if (ans>=mod) ans-=mod;
        }
    }
    printf("%d\n",ans);
    return 0;
}