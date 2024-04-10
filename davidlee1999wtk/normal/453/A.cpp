#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
double ksm(double a,int b)
{
    double c=1.0,d=a;
    while(b)
    {
        if(b&1) c*=d;
        d*=d;
        b>>=1;
    }
    return c;
}
int main()
{
    int m,n,i;
    double last=0,ans=0;
    cin>>m>>n;
    for(i=m;i>=1;i--)
    {
        ans+=(1.0-ksm(double(i-1)/double(m),n)-last)*double(i);
        last=1.0-ksm(double(i-1)/double(m),n);
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);