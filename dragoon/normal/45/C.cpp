#pragma warning(disable:4786)
#include<stdio.h>
#include<queue>
#include<assert.h>
#include<vector>
using namespace std;

#define ABS(X) ((X)>0?(X):(-(X)))

int next[200002],prev[200002];
int h[200002];

struct Pair
{
	int a, b, hd;
	Pair(int x, int y)
	{
		a = x;
		b = y;
		hd = ABS(h[a]-h[b]);
	}
};

bool operator<(Pair A, Pair B)
{
	if( A.hd > B.hd ) return 1;
	if( A.hd < B.hd ) return 0;

	if(A.a > B.a) return 1;
	return 0;
}

char word[200003];
priority_queue<Pair> S;
vector<Pair> V;
int done[200003];

int main()
{
	int n,i;
	Pair Y(0,0);
	Pair X(0,0);

	int b=0,g=0;

	scanf("%d%s",&n,word);
	for(i=0;i<n;i++) 
	{
		scanf("%d",&h[i]);
		prev[i] = i-1;
		next[i] = i+1;
		done[i]=0;

		if(word[i]=='B') b++; else g++;
	}

	if(g<b) b = g;

	for(i=0;i<n-1;i++)
	{
		if(word[i]!=word[i+1])
			S.push( Pair(i,i+1) );
	}

	while(!S.empty())
	{
		X = S.top();
		S.pop();
		Y = X;
//		S.erase(X);
		if(done[Y.a] || done[Y.b]) continue;
		done[Y.a]=1; done[Y.b]=1;
		V.push_back( Y );
		if(prev[Y.a]!=-1) next[ prev[Y.a] ] = next[ Y.b ];
		if(next[Y.b]!=n)  prev[ next[Y.b] ] = prev[ Y.a ];
		if(prev[Y.a]!=-1 && next[Y.b]!=n && word[prev[Y.a]]!=word[next[Y.b]])
			S.push( Pair(prev[Y.a],next[Y.b]) );
	}

	assert(V.size()==b);

	printf("%d\n",V.size());
	for(i=0;i<V.size();i++)
		printf("%d %d\n",V[i].a+1,V[i].b+1 );
	return 0;
}