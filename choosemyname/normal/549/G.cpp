#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int num[200010];
typedef pair<int,int> pii;
pii x[200010];
int main()
{
    int n,n1;
    cin>>n;
    for(n1=1;n1<=n;n1++)
    {
        scanf("%d",&num[n1]);
        x[n1]=make_pair(num[n1]+n1,n1);
    }
    sort(x+1,x+n+1);
    for(n1=1;n1<=n;n1++)
    {
        num[n1]=x[n1].first-n1;
        if(num[n1]<num[n1-1]||num[n1]<0)
        {
            cout<<":(";
            return 0;
        }
    }
    for(n1=1;n1<=n;n1++)
        cout<<num[n1]<<' ';
    
    
}