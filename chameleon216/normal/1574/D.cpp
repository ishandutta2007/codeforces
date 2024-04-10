#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <ctime>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long ll;
using namespace std;

const int MX=200100;
int N,M,num[11];
int C[11][MX];
int D[11];
set<ll> se,B;

const int Pri[13]=
{
	1000000007,
	1000000009,
	1000000021,
	1000000033,
	1000000087,
	1000000093,
	1000000097,
	1000000103,
	1000000123,
	1000000181,
	1000000207,
	1000000223,
	1000000321
};
const int Bs=1333331;
int P,Q;
void Init()
{
	P=Pri[rand()%13],Q=Pri[rand()%13];
	while(P==Q)Q=Pri[rand()%13];
}
ll Hash(int a[])
{
	ll g=0,h=0;
	Fr(i,1,N)
	{
		g=(g*Bs+a[i])%P;
		h=(h*Bs+a[i])%Q;
	}
//	printf("%lld %lld\n",g,h);
	return g<<31|h;
}


struct Node{int k[11],v;ll h;};
bool operator<(const Node& a,const Node& b)
{
	return a.v<b.v;
}

void Solve()
{
	priority_queue<Node> q;
	Node x;
	memset(x.k,0,sizeof(x.k)),x.v=0;
	Fr(i,1,N)x.k[i]=num[i],x.v+=C[i][num[i]];
	x.h=Hash(x.k),B.insert(x.h);
	q.push(x);
	while(!q.empty())
	{
		Node p=q.top();
		q.pop();
		if(!se.count(p.h))
		{
			Fr(i,1,N)printf("%d ",p.k[i]);
			putchar('\n');
			return;
		}
		Fr(i,1,N)if(p.k[i]>1)
		{
			Node y=p;
			y.v-=C[i][y.k[i]];
			--y.k[i];
			y.v+=C[i][y.k[i]];
			y.h=Hash(y.k);
			if(B.count(y.h))continue;
			B.insert(y.h);
			q.push(y);
		}
	}
}


int main()
{
	srand(time(0));
	Init();
	
	scanf("%d",&N);
	Fr(i,1,N)
	{
		scanf("%d",&num[i]);
		Fr(j,1,num[i])scanf("%d",&C[i][j]);
	}
	scanf("%d",&M);
	Fr(i,1,M)
	{
		Fr(j,1,N)scanf("%d",&D[j]);
		se.insert(Hash(D));
	}
	
	Solve();
	return 0;
}