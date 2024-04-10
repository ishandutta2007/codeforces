#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
long long a[500010];
priority_queue<long long> Q;
int main()
{
    int n;
    long long ss=0;
    cin>>n;
    while (!Q.empty())Q.pop();
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    {
        long long x;
        scanf("%lld",&x);
        Q.push(-a[i]-ss);
        long long sum=0;
        for(;!Q.empty()!=0 && Q.top()>=-ss-x;Q.pop())sum=sum-Q.top()-ss;
        ss+=x;
        sum+=1ll*Q.size()*x;
        printf("%lld%c",sum,i==n?'\n':' ');
    }
    return 0;
}