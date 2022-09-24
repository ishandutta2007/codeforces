#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

using namespace std;

long long U(long long a,long long b)
{
    if(a==0) return 0;
    long long sum;
    if(a<b){
        long long t=b;
        b=a;
        a=t;
    }

    sum = a/b;
    sum += U(a%b,b);

    return sum;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdin);

    long long n,k;

    scanf("%I64d %I64d",&n,&k);

    printf("%I64d\n",U(n,k));

    return 0;
}