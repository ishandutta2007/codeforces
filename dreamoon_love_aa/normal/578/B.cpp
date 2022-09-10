#include<cstdio>
#include<algorithm>
using namespace std;
const int SIZE = 2e5+2;
long long a[SIZE],prefix[SIZE],suffix[SIZE];
int main(){
    int n,k,x;
    scanf("%d%d%d", &n, &k, &x);
    long long mul=1;
    while(k--)
        mul *= x;
    for(int i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);
    for(int i = 1; i <= n; i++)
        prefix[i] = prefix[i-1] | a[i];
    for(int i = n; i > 0; i--)
        suffix[i] = suffix[i+1] | a[i];
    long long ans = 0;
    for(int i= 1; i <= n; i++)
        ans = max(ans, prefix[i-1] | (a[i] * mul) | suffix[i+1]);
    printf("%I64d\n",ans);
}