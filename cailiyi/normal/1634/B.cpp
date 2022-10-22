#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 100000
using namespace std;
int T,n,x;
long long y;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %lld",&n,&x,&y),x&=1,y&=1;
        for(int i=1,a;i<=n;++i) scanf("%d",&a),x^=a&1;
        x==y?puts("Alice"):puts("Bob");
    }
    return 0;
}