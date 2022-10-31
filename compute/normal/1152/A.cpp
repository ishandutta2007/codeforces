#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int arr[maxn];
int brr[maxn];
int main()
{
    int n,m;
    int odda=0,oddb=0;
    scanf("%d%d",&n,&m);
    for(int i=0,tmp;i<n;i++)
    {
        scanf("%d",&tmp);
        if(tmp%2) odda++;
    }
    for(int i=0,tmp;i<m;i++)
    {
        scanf("%d",&tmp);
        if(tmp%2) oddb++;
    }
    printf("%d\n",min(odda,m-oddb)+min(n-odda,oddb));
}