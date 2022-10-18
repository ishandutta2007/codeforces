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
#define ABS(X) ((X) < 0 ? (-(X)) : (X))
#define S(X) ((X)*(X))

typedef pair<int,int> PII;
typedef __int64 LL;

struct SS
{
	vector<int> V;
	string name;
	int score;
	int win;
}S[1002];

bool a(SS A, SS B)
{
	if(A.score < B.score) return 0;
	if(A.score > B.score) return 1;

	int i;
	for(i=0;i<A.V.size() && i<B.V.size();i++)
		if(A.V[i] < B.V[i])
			return 1;
		else if(A.V[i] > B.V[i])
			return 0;

	if(A.V.size() > B.V.size()) return 1;
	return 0;
}

bool b(SS A, SS B)
{
	if(A.win < B.win) return 0;
	if(A.win > B.win) return 1;

	if(A.score < B.score) return 0;
	if(A.score > B.score) return 1;

	int i;
	for(i=0;i<A.V.size() && i<B.V.size();i++)
		if(A.V[i] < B.V[i])
			return 1;
		else if(A.V[i] > B.V[i])
			return 0;

	if(A.V.size() > B.V.size()) return 1;
	return 0;
}

map<string,int> M;
int cnt;
int point[100]={0,25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

int main()
{
	int i,t,j,n;
	string name1,name2;
	char name[100];

	for(i=11;i<100;i++) point[i]=0;

	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%s",name);
			if(M.find(name)==M.end()) 
			{
				M[name]=cnt;
				S[cnt].score = S[cnt].win = 0;
				S[cnt].name = name;
				cnt++;
			}

			S[ M[name ] ].V.push_back(j);
			S[ M[name ] ].score += point[j];
			if(j==1) S[M[name]].win ++;
		}
	}

	for(i=0;i<cnt;i++)
		sort(S[i].V.begin(),S[i].V.end());

	sort(S,S+cnt,a);
	name1 = S[0].name;
	sort(S,S+cnt,b);
	name2 = S[0].name;

	printf("%s\n%s\n",name1.c_str(),name2.c_str());



	return 0;
}