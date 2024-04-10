#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

int c[100005],v[100005];
long long mx[100005];
bool was[100005];

int main() {
//  freopen("input.txt","r", stdin);
//  freopen("output.txt", "w", stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;++i)
        scanf("%d",&v[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&c[i]);
    int a,b;
    for(int t=0;t<q;++t) {
        memset(mx,0,sizeof(mx));
        memset(was,0,sizeof(was));
        scanf("%d%d",&a,&b);
        long long mx1=0,mx2=0,ans=0; int c1=0,c2=0;
        for(int i=0;i<n;++i) {
            long long v1=mx1+1LL*(c1==c[i] ? a : b)*v[i],v2=mx2+1LL*(c2==c[i] ? a : b)*v[i];
            if (was[c[i]]) v1=max(v1,mx[c[i]]+1LL*a*v[i]);
            long long cur=max(v1,v2); ans=max(ans,cur);
            if (cur>mx1) {
                if (c[i]==c2) {
                    swap(c1,c2);
                    swap(mx1,mx2);
                    mx1=cur;
                } else {
                    if (c1==c[i]) mx1=cur;
                    else {
                        swap(c1,c2);
                        swap(mx1,mx2);
                        mx1=cur; c1=c[i];
                    }
                }
            } else {
                if (cur>mx2) {
                    if (c1!=c[i]) {
                        c2=c[i];
                        mx2=cur;
                    }
                }
            }
            if (was[c[i]]) mx[c[i]]=max(cur,mx[c[i]]);
            else mx[c[i]]=cur;
            was[c[i]]=true;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}