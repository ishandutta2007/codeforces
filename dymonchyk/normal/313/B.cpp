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

char str[100005];
int sum[100005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    gets(str);
    int len=strlen(str);
    for(int i=0;i<len-1;++i) {
        sum[i]=str[i]==str[i+1];
        if (i) sum[i]+=sum[i-1];
    }
    int n,l,r;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d%d",&l,&r); --l; --r;
        printf("%d\n",sum[r-1]-(l>0 ? sum[l-1] : 0));
    }
    return 0;
}