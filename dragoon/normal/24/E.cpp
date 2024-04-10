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
#include<assert.h>
using namespace std;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(X) ((X) < 0 ? (-(X)) : (X))
#define S(X) ((X)*(X))

typedef pair<int,int> PII;
typedef __int64 LL;

struct XX
{
	int x, v;

	XX(int a, int b)
	{
		x=a;
		v=b;
	}

	XX(){}
};

XX S[500002];

int top, n, i, x, v;
int lo, hi, mid;
double t, ans=-1;
LL xx=1;

int main()
{
	top=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&v);
		if(v < 0)
		{
			//check
			if(top==0) continue;

			lo=0;
			hi = top-1;

			while(lo < hi)
			{
				mid = (lo+hi)/2;

//				t = (x - S[mid].x)/(S[mid].v - v);
				if(mid==top-1)
				{
					assert(0);
					if( x-S[mid].x <= 0 )
						lo = mid+1;
					else
						hi = mid;
				}
				else
				{
//					ts = (S[mid-1].x - S[mid].x)/(S[mid].v - S[mid-1].v);
					if( xx*(x-S[mid].x)*(S[mid].v - S[mid+1].v) < xx*(S[mid+1].x - S[mid].x)*(S[mid].v - v) )
						lo = mid+1;
					else if( xx*(x-S[mid].x)*(S[mid].v - S[mid+1].v) > xx*(S[mid+1].x - S[mid].x)*(S[mid].v - v) )
						hi = mid;
					else
					{
						t = 1.*(x - S[mid].x)/(S[mid].v - v);

						if(ans < -0.5 || ans>t) ans = t;

					}
				}
			}

			t = 1.*(x - S[lo].x)/(S[lo].v - v);

			if(ans < -0.5 || ans>t) ans = t;
		}

		if(v > 0)
		{
			//insert

			if(top==0) {S[top++] = XX(x,v); continue;}

			while(top)
			{
				if( v == S[top-1].v )
				{
					top--;
					continue;
				}

//				t = (x - S[top-1].x)/(S[top-1].v - v);
				if(top==1)
				{
					if(v >= S[top-1].v) S[top-1] = XX(x,v);
					else S[top++]=XX(x,v);
					break;
				}
				else
				{
//					te = (S[top-2].x - S[top-1].x)/(S[top-1].v - S[top-2].v);

					if(v >= S[top-1].v)
					{
						top--; continue;
					}

					if( xx*(x - S[top-1].x)*(-S[top-1].v + S[top-2].v) > xx*(-S[top-2].x + S[top-1].x)*(S[top-1].v - v) )
					{ top--; continue; }
					else
					{
						S[top] = XX(x, v);
						top++;
						break;
					}
				}
			}

			if(top==0)
			{
				S[top++]=XX(x,v);
			}

		}
	}

	printf("%.20lf\n",ans);

	return 0;
}