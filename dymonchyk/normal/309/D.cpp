#include <cstdio>
using namespace std;
int main() {
    int n,m;
    scanf("%d%d",&n,&m); ++n;
    long long ans=0;
    for(int a=m+1;2*a<=n;++a) {
        int c=n-m-1,cur=0;
        for(int b=m+1;b<n-m&&c>m;++b) {
            while(c>m&&-b*(n+c)<=a*(2*a-b-2*n+c)) --c;
            cur+=c-m;
        }
        ans+=cur*(1+(a+a!=n));
    }
    printf("%I64d\n",3*ans);
    return 0;
}