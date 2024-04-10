#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<math.h>
#include<stack>
using namespace std;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(X) ((X)>0?(X):(-(X)))
#define S(X) ((X)*(X))
#define D(x1,yy1,x2,y2) (sqrt( S((x1)-(x2)) + S((yy1)-(y2)) ))
#define EPS 1e-8
#define IN(a,b,c) if(a>=b && a<=c)
#define CLEAR(a) memset(a,0,sizeof(a))
#define in(a,b,c) (a>=b && a<=c)
#define SORT(A) sort(A.begin(),A.end())
#define SZ(X) (int)(X.size())
#define D2(x1,yy1,x2,y2) ( S((x1)-(x2)) + S((yy1)-(y2)) )

typedef pair<int,int> PII;
typedef __int64 LL;

//int dr[]={0,0,1,-1,-1,-1,1,1};
//int dc[]={1,-1,0,0,1,-1,1,-1};

int R[100004];
PII V[100004];
int counts[100004];

vector<int> Vec[100004];

inline int rev(int x)
{
	if(R[x]) return R[x];

	int ok = 0,y=0,z;

	while(x)
	{
		z=x%10;
		x/=10;
		if(z) ok = 1;
		if(ok) y=y*10 + z;
	}

	return y;
}

int GCD[100004];

int gcd(int a, int b,int c = 0)
{
	if(c==0 && GCD[a]) return GCD[a];

	int ans;

	if(a%b==0) ans = b;
	else ans = gcd(b,a%b,1);

	if(c==0) GCD[a] = ans;
	return ans;

}

int main()
{
	int mx,my,w,sz,id,ax,ay,k,g;
	LL inf, mmin, ans,now_y;
	int i,j,cnt;
	PII X;
	
	scanf("%d%d%d",&mx,&my,&w);

	LL xx = mx;
	if(xx*my<w) {printf("-1\n"); return 0;}

	for(i=1;i<=my;i++)
	{
		k = i;
		R[i] = j = rev(i);

		g = gcd(k,j); k/=g; j/=g;
		V[i-1]=( PII(j,k) );
	}

	sort(V,V+my);

	sz = my;
	for(i=1,j=1;i<sz;i++)
	{
		if(V[i]!=V[j-1])
		{
			V[j++] = V[i];
		}

	}

	sz = j;

	for(i=1;i<=my;i++)
	{
		j = R[i];
		k = i;
		g=gcd(i,j); j/=g; k/=g;

		id = lower_bound(V,V+sz,PII(j,k)) - V;

		Vec[id].push_back( i );
	}

	for(i=0;i<sz;i++)
		Vec[i].push_back(100000000);

	mmin = 1000000;
	mmin *= 1000000;

	inf = mmin;

	ans = 0;
	now_y = my;
	for(i=1;i<=mx;i++)
	{
		j = rev(i);
		k = i;

		g = gcd(k,j);
		k/=g; j/=g;

		X = PII(k,j);

		id = lower_bound(V,V+sz,X)-V;
		if(id==my || V[id]!=X)
			continue;

		cnt = lower_bound(Vec[id].begin(),Vec[id].end(),now_y) - Vec[id].begin();

		if(Vec[id][cnt]!=now_y) cnt--;

		counts[id]++;

		ans += (cnt+1);

		while(ans>=w)
		{
			if(now_y*i < mmin) 
			{
				mmin = now_y*i;
				ax = i;
				ay = now_y;
			}

			j = rev(now_y);
			k = now_y;
			g = gcd(k,j); j/=g; k/=g;
			id = lower_bound(V,V+sz,PII(j,k)) - V;

			ans -= counts[id];
			now_y--;
		}
	}

	if(mmin == inf) printf("-1\n"); else printf("%d %d\n",ax,ay);

	
	return 0;
}