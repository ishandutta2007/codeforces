#pragma warning(disable:4786)
#include<stdio.h>
#include<queue>
#include<stack>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<map>
#include<set>
#include<math.h>
#include<sstream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define S(X) ((X)*(X))
#define ABS(X) ((X)>0?(X):(-(X)))

typedef unsigned __int64 LL;

typedef pair<int,int> PLI;
map<PLI, LL> M,Z;

int dp(LL B, int carry, LL A, LL &X, int cnt)
{
	LL cX, tX;
	int c,flag=0,x,z;

	if(carry && A==0) return 0;
	if(A==0) 
	{
		if(B) return 0;

		X=0; 
		return 1;
	}

	if( Z.find( PLI(cnt,carry) ) != Z.end() )
	{
		c = Z[PLI(cnt,carry)];
		if( c==1 ) return 0;
		return M[ PLI(cnt,carry) ];
	}

	Z[ PLI(cnt,carry) ] = 2;

	//try 1 as lsb of Y
	x = (B&1)^1; //x as lsb of X
	z = A&1;
	if(x+1+carry>z)
	{
		if( (x+1+carry)%2 == z )
		{
			c = dp(B>>1, 1, A>>1, cX,cnt+1);
			if(c)
			{
				cX = (cX<<1)|x;
				if(!flag || tX > cX) flag=1, tX=cX;
			}

		}
	}
	else if(x+1+carry == z)
	{
		c = dp(B>>1, 0, A>>1, cX,cnt+1);
		if(c)
		{
			cX = (cX<<1)|x;
			if(!flag || tX > cX) flag=1, tX=cX;
		}
	}

	//try 0 as lsb of Y
	x = (B&1);
	z = A&1;
	if(x+carry>z)
	{
		if( (x+carry)%2 == z )
		{
			c = dp(B>>1, 1, A>>1, cX,cnt+1);
			if(c)
			{
				cX = (cX<<1)|x;
				if(!flag || tX > cX) flag=1, tX=cX;
			}
		}
	}
	else if(x+carry == z)
	{
		c = dp(B>>1, 0, A>>1, cX,cnt+1);
		if(c)
		{
			cX = (cX<<1)|x;
			if(!flag || tX > cX) flag=1, tX=cX;
		}
	}

	if(!flag) 
	{
		Z[ PLI(cnt,carry) ] = 1;
		return 0;
	}

	M[ PLI(cnt,carry) ] = X = tX;
	return 1;

}

int main()
{
	LL A,B,X,Y;
	int c;

	scanf("%I64u%I64u",&A,&B);
	c = dp(B,0,A,X,0);
	Y = B ^ X;
	if(c) printf("%I64u %I64u\n",X,Y);
	else printf("-1\n");

	return 0;
}