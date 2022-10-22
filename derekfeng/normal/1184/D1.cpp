/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++) 
#define LL long long
#define pii pair <int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

int n,k,m,t,x,y;

int main()
{
	cin>>n>>k>>m>>t;
	while(t--)
	{
		scanf("%d%d",&x,&y);
		if(x==0)
		{
			if(k<=y) n=y;
			else
			{
				k-=y;
				n-=y;
			}
		}
		else
		{
			if(y<=k)
			{
				k++;
				n++;
			}
			else n++;
		}
		cout<<n<<' '<<k<<endl;
	}
	rt0;
}