#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int module = 1e9+7;
const int INF = 1e9;
const int N = 400;
const int NN = 1000;

int n,nn,s,t;
pii points[N];
int mflow[NN][NN],cflow[NN][NN];
double cost[NN][NN];

int acount;
double adist;

void add(int v1, int v2, int fl, double cst)
{
	cost[v1][v2] = cst;
	cost[v2][v1] = -cst;
	mflow[v1][v2] = fl;
}

double phi[NN];

double dist[NN];
int used[NN],pr[NN];
bool djkstra()
{
	for (int i=0; i<nn; i++)
	{
		dist[i] = INF;
		used[i] = 0;
	}
	dist[s] = 0;
	pr[s] = -1;
	while (1)
	{
		int vert=-1;
		for (int i=0; i<nn; i++)
			if (!used[i] && (vert==-1 || dist[i]<dist[vert]))
				vert = i;
		if (vert==-1)
			break;
		used[vert]=1;
		for (int i=0; i<nn; i++)
			if (mflow[vert][i]-cflow[vert][i]>0 && 
				dist[i]>dist[vert]+cost[vert][i]+phi[vert]-phi[i])
			{
				dist[i]=dist[vert]+cost[vert][i]+phi[vert]-phi[i];
				pr[i]=vert;
			}
	}
	if (dist[t] == INF)return false;
	for (int i=0; i<nn; i++)
		phi[i] += used[i] ? dist[i] : dist[t];
	int ccount=INF;
	for (int i=t; pr[i]!=-1; i=pr[i])
		ccount = min(ccount, mflow[pr[i]][i]-cflow[pr[i]][i]);
	acount += ccount;
	for (int i=t; pr[i]!=-1; i=pr[i])
	{
		adist += cost[pr[i]][i]*ccount;
		cflow[pr[i]][i] += ccount;
		cflow[i][pr[i]] -= ccount;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> points[i].first >> points[i].second;
	
	nn = 2*n+2;
	s = 0;
	t = 2*n+1;

	for (int i=1; i<=n; i++)
		add(s, i, 2, 0);
	
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (points[j].second > points[i].second)
				add(j+1, i+1+n, 1, sqrt(pow(.0+points[i].first-points[j].first,2.0)+
								 pow(.0+points[i].second-points[j].second,2.0)));

	for (int i=1; i<=n; i++)
		add(i+n, t, 1, 0);

	acount = 0;
	adist = 0;
	while (djkstra());

	cout << fixed << setprecision(15);
	if (acount == n-1)
		cout << adist << endl;
	else
		cout << -1 << endl;
	return 0;
}