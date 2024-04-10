#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    printf("%d\n",min(a[n-1]-a[1],a[n-2]-a[0]));
    return 0;
}