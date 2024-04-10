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
#include<string>
#include<bitset>
#define INF 1000000000
#define N 100005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int a[11];
int main()
{
	int i,now,op1,op2,n,f1,f2;
	for(i=1;i<=6;i++)
		cin>>a[i];
	int ans=0;
	now=a[4];
	op1=a[3],op2=a[5];
	n=a[2]+a[3];
	while(n--)
	{
		if(op1>=1)
			f1=1;
		else f1=-1;
		if(op2>=1)
			f2=1;
		else f2=-1;
		op1--,op2--;
		if(f1+f2==0)
			ans+=now*2;
		else if(f1+f2==2)
			ans=ans+now*2+1;
		else ans=ans+now*2-1;
		now+=(f1+f2)/2;	
		//debug(now);
		//debug(f1);
		//debug(f2);
	}
	cout<<ans<<endl;
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);