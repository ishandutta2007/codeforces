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
int main()
{
int n,m;
cin>>n>>m;
int ans=0;
for(int i=1;i<=m;i++)
    if(i<=n&&m%i==0&&m/i<=n)
        ans++;
   cout<<ans;
  }