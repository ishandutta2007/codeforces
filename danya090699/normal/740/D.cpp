#include <iostream>
#include <fstream>
#include <vector>
#define int long long
using namespace std;
struct el
{
	int pr, le, va, q=0, an;
};
vector <int> *sv;
el *ve;
int rec(int nu)
{
	int q2=0;
	for(int a=0; a<sv[nu].size(); a++) q2+=rec(sv[nu][a]);
	ve[nu].an=q2;
	q2++, q2-=ve[nu].q;
	return q2;
}
main()
{
	ifstream in("input.txt");
	int n, lq=18;
	cin>>n;
	sv=new vector <int>[n], ve=new el[n];
	for(int a=0; a<n; a++) cin>>ve[a].va;
	ve[0].pr=0, ve[0].le=0;
	for(int a=1; a<n; a++)
	{
		cin>>ve[a].pr>>ve[a].le;
		ve[a].pr--;
		sv[ve[a].pr].push_back(a);
	}
	int st2[lq];
	st2[0]=1;
	for(int a=1; a<lq; a++) st2[a]=st2[a-1]*2;
	int up[lq][n][2];
	for(int a=0; a<n; a++)
	{
		up[0][a][0]=ve[a].pr, up[0][a][1]=ve[a].le;
	}
	for(int a=1; a<lq; a++)
	{
		for(int b=0; b<n; b++)
		{
			int pre=up[a-1][b][0];
			up[a][b][0]=up[a-1][pre][0];
			up[a][b][1]=up[a-1][b][1]+up[a-1][pre][1]; 
		}
	}
	for(int a=0; a<n; a++)
	{
		int cu=a;
		for(int b=lq-1; b>=0; b--)
		{
			if(ve[a].va>=up[b][cu][1])
			{
				ve[a].va-=up[b][cu][1];
				cu=up[b][cu][0];
			}
		}
		ve[cu].q++;
	}
	rec(0);
	for(int a=0; a<n; a++) cout<<ve[a].an<<" ";
}