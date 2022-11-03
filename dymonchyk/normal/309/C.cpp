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

int a[1000006],cnt[30];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,t;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i) scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<m;++i) {
        scanf("%d",&t);
        cnt[t]++;
    }
    int ncnt[30];
    int l=0,r=m+1;
    while(r-l>1) {
        int mid=(l+r)>>1;
        memcpy(ncnt,cnt,sizeof(ncnt));
        int sum=0,last=29;
        for(int i=0;i<30;++i) {
            sum+=ncnt[i];
            if (sum>=mid) {
                ncnt[i]-=sum-mid;
                last=i;
                break;
            }
        }
        for(int i=n-1;i>=0&&last!=-1;--i) {
            int left=a[i];
            for(int j=last;j>=0;--j) {
                int add=left>>j;
                if (add>=ncnt[j]) {
                    left-=ncnt[j]<<j;
                    ncnt[j]=0;
                    if (last==j) --last;
                } else {
                    ncnt[j]-=add;
                    left-=add<<j;
                }
            }
        }
        if (last==-1) l=mid;
        else r=mid;
    }
    printf("%d\n",l);
    return 0;
}