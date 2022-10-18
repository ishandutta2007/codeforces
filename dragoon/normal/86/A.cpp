#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define S(X) ((X)*(X))
#define ABS(X) ((X)>0?(X):(-(X)))

typedef pair<int,int> PII;
typedef __int64 LL;

LL p10[40];
LL ans;

inline void check(LL a, LL b, int c)
{
	LL now;
	now = a*(p10[c]-1)-a*a;
	ans=MAX(ans,now);
	now = b*(p10[c]-1)-b*b;
	ans=MAX(ans,now);

	LL h = (p10[c]-1)/2, A;
	int i;

	for(i=-2;i<=2;i++)
	{
		A = h+i;
		if(A<a || b<A) continue;
		now = A*(p10[c]-1)-A*A;
		ans=MAX(ans,now);
	}
}

char word[100];

int main()
{
	int i;
	LL L, R;
	int l1, l2;

	p10[0]=1;
	for(i=1;i<=30;i++) p10[i]=p10[i-1]*10;

	scanf("%I64d%I64d",&L,&R);
//	while(scanf("%I64d%I64d",&L,&R)!=EOF){

	sprintf(word,"%I64d",L);
	l1 = strlen(word);
	sprintf(word,"%I64d",R);
	l2 = strlen(word);

	ans = -1;
	if(l1==l2)
		check(L,R,l1);
	else
	{
		check(L,p10[l1]-1,l1);
		check(p10[l2-1],R,l2);
		for(i=l1+1;i<l2;i++)
			check(p10[i-1],p10[i]-1,i);
	}

	printf("%I64d\n",ans);



//	}
	return 0;
}