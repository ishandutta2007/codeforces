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
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	int x=a+b+f;
	int i=x*x;
	i-=b*b;
	i-=d*d;
	i-=f*f;
	cout<<i<<endl;
}