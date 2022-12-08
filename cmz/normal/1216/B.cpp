#include<iostream>
#include<algorithm>
#include<string.h>
#include<iomanip>
#include<math.h>
#include<vector>
#include <queue>
#define PI acos(-1.0)
const long long INF = 1e18+10;
const long long NINF = -INF - 1;
typedef long long ll;
using namespace std;
struct node{
    int x,id;
}a[1010];
bool cmp(node x,node y)
{
    return x.x<y.x;
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i].x,a[i].id=i;
    sort(a+1,a+n+1,cmp);
    ll t=0;
    for(int i=n;i>=1;i--)
    {
        t+=(n-i)*a[i].x+1;
    }
    cout<<t<<endl;
    for(int i=n;i>=1;i--)
    {
        cout<<a[i].id<<" ";
    }
    cout<<endl;
    return 0;
}