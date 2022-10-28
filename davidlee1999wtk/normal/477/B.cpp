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
typedef pair<LL,int> pii;
int a[5]={0,1,2,3,5};
int main()
{
    int n,k;
    int i,j;
    cin>>n>>k;
    cout<<(5+(n-1)*6)*k<<endl;
    for(i=0;i<n;i++)
    {
        for(j=1;j<=4;j++)
            printf("%d ",(a[j]+i*6)*k);
        printf("\n");
    }
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);