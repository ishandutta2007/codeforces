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
#include <cstring>

using namespace std;

int n,arr[100005];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%d",&n);
    bool one=true;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if (arr[i]!=1) one=false;
    }
    if (one)
    {
        arr[n-1]=2;
        printf("%d",arr[0]);
        for(int i=1;i<n;i++)
            printf(" %d",arr[i]);
    }
    else
    {
        sort(arr,arr+n);
        for(int i=n-1;i>0;i--) arr[i]=arr[i-1];
        printf("1");
        for(int i=1;i<n;i++)
            printf(" %d",arr[i]);
    }
    printf("\n");
    return 0;
}