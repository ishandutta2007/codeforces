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

int fen[100005];
int mod=1000000007;

void upd(int n,int pos,int val) {
    for(;pos<=n;pos|=(pos+1)) {
        fen[pos]+=val;
        if (fen[pos]>=mod) fen[pos]-=mod;
    }
}

int fnd(int pos) {
    int ret=0;
    for(;pos>=0;pos=(pos&(pos+1))-1) {
        ret+=fen[pos];
        if (ret>=mod) ret-=mod;
    }
    return ret;
}

pair <int,int> v[100005];
pair <int,int> to[100005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d",&a);
        v[i]=make_pair(a,i);
    }
    sort(v,v+n);
    int out=0;
    for(int i=0;i<n;) {
        int val=v[i].first,cnt=0,mul=val;
        int g=0,last=-1;
        while(i<n&&v[i].first==val) {
            g=(1LL*g*val+(fnd(v[i].second)-fnd(last)))%mod;
            if (g<0) g+=mod;
            int ans=(mul+1LL*val*g)%mod;
            out+=ans;
            if (out>=mod) out-=mod;
            to[cnt++]=make_pair(v[i].second,ans);
            last=v[i].second;
            ++i; mul=(1LL*mul*val)%mod;
        }
        for(int j=0;j<cnt;++j)
            upd(n+1,to[j].first,to[j].second);
    }
    printf("%d\n",out);
    return 0;
}