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
int a[200005];
int main()
{
    LL n,b1=2000000000,b2=-1,c1,c2,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(b1==a[i]) c1++;
        if(b1>a[i])
            b1=a[i],c1=1;
        if(b2==a[i]) c2++;
        if(b2<a[i])
            b2=a[i],c2=1;
    }
    cout<<b2-b1<<' ';
    if(b1!=b2)
        cout<<c1*c2<<endl;
    else cout<<c1*(c2-1)/2;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);