#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#define iter map <char, int>::iterator
using namespace std;
struct el
{
	map <char, int> ne, go;
	int leaf=-1;
	int pr=0;
	char prc;
	int link=-1;
};
vector <el> bor(1);
void get_go(int v, char sy);
void get_link(int v)
{
	int pa=bor[v].pr;
	char sy=bor[v].prc;
	if((v==0)or(pa==0)) bor[v].link=0;
	else
	{
		if(bor[pa].link==-1) get_link(pa);
		iter it=bor[bor[pa].link].go.find(sy);
		if(it==bor[bor[pa].link].go.end()) get_go(bor[pa].link, sy);
		bor[v].link=bor[bor[pa].link].go[sy];
	}
}
void get_go(int v, char sy)
{
	iter it=bor[v].ne.find(sy);
	if(it==bor[v].ne.end())
	{
		if(v==0) bor[v].go[sy]=0;
		else
		{
			if(bor[v].link==-1) get_link(v);
			iter it=bor[bor[v].link].go.find(sy);
			if(it==bor[bor[v].link].go.end()) get_go(bor[v].link, sy);
			bor[v].go[sy]=bor[bor[v].link].go[sy];
		}
	}
	else bor[v].go[sy]=bor[v].ne[sy];
}
int main()
{
	ifstream in("input.txt");
	int n, k, g;
	string s;
	cin>>n>>k>>s>>g;
	for(int a=0; a<g; a++)
	{
		string cu;
		cin>>cu;
		int v=0;
		for(int b=0; b<k; b++)
		{
			iter it=bor[v].ne.find(cu[b]);
			if(it==bor[v].ne.end())
			{
				el* nel=new el;
				bor[v].ne[cu[b]]=bor.size();
				bor.push_back(*nel);
				bor.back().pr=v;
				bor.back().prc=cu[b];
			}
			v=bor[v].ne[cu[b]];
		}
		bor[v].leaf=a;
	}
	s+=s;
	int v=0, sov[s.size()];
	set <int> se[k];
	for(int a=0; a<s.size(); a++)
	{
		char sy=s[a];
		iter it=bor[v].go.find(sy);
		if(it==bor[v].go.end()) get_go(v, sy);
		v=bor[v].go[sy];
		int nu=bor[v].leaf;
		if(nu!=-1)
		{
			sov[a+1-k]=nu;
			se[(a+1-k)%k].insert(nu);
		}
	}
	bool fo=0;
	for(int a=0; a<k; a++)
	{
		if(se[a].size()==n)
		{
			cout<<"YES\n";
			for(int b=0; b<n; b++) cout<<sov[a+b*k]+1<<" ";
			fo=1;
			break;
		}
	}
	if(fo==0) cout<<"NO";
}