#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> P, N, Z;
int szp,szn,szz,flag=0;

void printP()
{
	int i;
	for(i=0;i<szp;i++)
	{
		if(flag) printf(" ");
		printf("%d",P[i]);
		flag=1;
	}
}

void printZ()
{
	int i;
	for(i=0;i<szz;i++)
	{
		if(flag) printf(" ");
		printf("%d",Z[i]);
		flag=1;
	}
}

void printN(int a)
{
	int i;
	for(i=0;i<szn-a;i++)
	{
		if(flag) printf(" ");
		printf("%d",N[i]);
		flag=1;
	}
}

int main()
{
	int n, i,a;

//	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&n);
		flag= 0;
		P.clear();
		N.clear();
		Z.clear();

		for(i=0;i<n;i++)
		{
			scanf("%d",&a);

			if(a>0) P.push_back(a);
			else if(a<0) N.push_back(a);
			else Z.push_back(a);
		}

		if(P.size()) sort(P.begin(),P.end());
		if(N.size()) sort(N.begin(),N.end());

		szp = P.size();
		szn = N.size();
		szz = Z.size();

		for(i=0;i<P.size();i++) 
		{
			if(flag) printf(" ");
			printf("%d",P[i]);
			flag=1;
		}

		if(P.size()==0 && Z.size()==0 && N.size()==1) a = 0;
		else if(N.size()%2==0) a = 0;
		else a = 1;

		for(i=0;i<N.size() - a;i++)
		{
			if(flag) printf(" ");
			printf("%d",N[i]);
			flag=1;
		}

		if( (P.size()==0 && N.size()==0) || (P.size()==0 && N.size()==1) )
			for(i=0;i<Z.size();i++)
			{
				if(flag) printf(" ");
				printf("%d",Z[i]);
				flag=1;
			}
/*
		if(szn%2==0)
		{
			printP();
			printN(0);

			if(!szn && !szp) printZ();
		}
		else if(szn > 1)
		{
			printP();
			printN(1);
		}
		else if(szn==1 && szp>0)
		{
			printP();
		}
		else
		{
			printZ();
			printN(0);
		}
*/
		printf("\n");
	}

	return 0;
}