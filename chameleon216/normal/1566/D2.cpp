#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long ll;
using namespace std;

const int MX=100100;
int N,M;

struct Pt
{
	int a,id;
}P[MX];
bool Comp1(const Pt& a,const Pt& b)
{
	return a.a!=b.a?a.a<b.a:a.id<b.id;
}
bool Comp2(const Pt& a,const Pt& b)
{
	return a.a!=b.a?a.a<b.a:a.id>b.id;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d%d",&N,&M);
		Fr(i,1,N*M)scanf("%d",&P[i].a),P[i].id=i;
		sort(P+1,P+N*M+1,Comp1);
		Fr(i,1,N)sort(P+(i-1)*M+1,P+i*M+1,Comp2);
		int sum=0;
		Fr(i,1,N)
		{
			int b=(i-1)*M+1,e=i*M;
			Fr(j,b,e)Fr(k,j+1,e)if(P[j].id<P[k].id)
				++sum;
		}
		printf("%d\n",sum);
	}
	return 0;
}