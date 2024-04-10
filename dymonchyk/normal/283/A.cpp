#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <sstream>
#include <ctime>

using namespace std;

long long add[200005];
long long val[200005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,t,a,x,k;
    scanf("%d",&n);
    long long sum=0; int cnt=1;
    while(n--) {
        scanf("%d",&t);
        if (t==1) {
            scanf("%d%d",&a,&x);
            add[a-1]+=x;
            sum+=1LL*a*x;
        } else if (t==2) {
            scanf("%d",&k);
            val[cnt++]=k;
            sum+=k;
        } else {
            if (cnt>1) {
                --cnt;
                sum-=val[cnt]+add[cnt];
                add[cnt-1]+=add[cnt]; add[cnt]=0;
            }
        }
        printf("%.7lf\n",1.0*sum/cnt);
    }
    return 0;
}