#pragma warning(disable:4786)
#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<utility>
#include<vector>
using namespace std;

typedef pair<int,int> PII;
vector<PII> ans;
int ansd;

struct A
{
	int a;
	A(int y) {a=y;}
};

struct B
{
	int b;
	B(int y) {b=y;}
};

bool operator<(A x, A y) { return x.a < y.a; }
bool operator<(B x, B y) { return x.b > y.b; }

multiset<A> S1;
multiset<A>::iterator lo;
multiset<B> S2;
multiset<B>::iterator hi;

int h[100006];
int i,j,n,k;

int count[1000002];

int main()
{
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
//		h[i]=rand()%10000;
		scanf("%d",&h[i]);
	}

	i=1;
	j=1;
	S1.insert(A(h[1]));
	S2.insert(B(h[1]));

	count[h[1]]++;

	ans.push_back( PII(1,1) );
	ansd = 1;

	for(j=2;j<=n;j++)
	{
		S1.insert(A(h[j]));
		S2.insert(B(h[j]));

		count[h[j]]++;

//printf("%d\n",S1.size());

		lo = S1.begin();
		hi = S2.begin();

		while(hi->b - lo->a > k)
		{
//			printf(">>>>>>>%d %d\n",lo->a,hi->b);

			count[h[i]]--;
			if(count[h[i]]) {i++; continue;}

			S1.erase(A(h[i]));
			S2.erase(B(h[i]));
			lo=S1.begin();
			hi=S2.begin();
//			printf(">>>>>>>%d %d\n",lo->a,hi->b);
			i++;
		}

		if(j-i+1 > ansd)
			ans.clear();
		
		if(ansd > j-i+1)
			continue;

		ansd = j-i+1;
		ans.push_back( PII(i,j) );
	}

	printf("%d %d\n",ansd,ans.size());
	for(i=0;i<ans.size();i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}