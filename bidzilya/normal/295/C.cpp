#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int module = 1e9+7;

typedef long long ll;
typedef pair<int, int> pii;

int n,k;
int c1,c2;
queue<int> q[4];
int mp[51][51][51][2],mc[51][51][51][2];
int C[51][51];

int main()
{
//	ifstream cin("input.txt");
	//ofstream cout("output.txt");
	C[0][0]=1;
	for (int i=1; i<51; i++)
	{
		C[0][i]=0;
		C[i][0]=1;
	}
	for (int i=1; i<51; i++)
		for (int j=1; j<51; j++)
			C[i][j] = (C[i-1][j-1]+C[i-1][j])%module;
	cin >> n >> k;
	for (int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		if (x==50)
			c1++;
		else
			c2++;
	}
	q[0].push(c1);
	q[1].push(c2);
	q[2].push(0);
	q[3].push(0);
	for (int i=0; i<51; i++)
		for (int j=0; j<51; j++)
			for (int k=0; k<51; k++)
				for (int l=0; l<2; l++)
					mp[i][j][k][l]=-1;
	mp[c1][c2][0][0]=0;
	mc[c1][c2][0][0]=1;
	while (!q[0].empty())
	{
		int ta,tb,tc,td;
		ta = q[0].front();
		tb = q[1].front();
		tc = q[2].front();
		td = q[3].front();
		q[0].pop();
		q[1].pop();
		q[2].pop();
		q[3].pop();
		if (td == 0)
		for (int na=0; na<=ta; na++)
			for (int nb=0; nb<=tb; nb++)
				if (na*50 + nb*100 <= k && na+nb>0)
				{
					if (mp[ta-na][tb-nb][tc+na][1]==-1)
					{
						mp[ta-na][tb-nb][tc+na][1]=mp[ta][tb][tc][0]+1;
						mc[ta-na][tb-nb][tc+na][1]=(1LL*((1LL*mc[ta][tb][tc][0]*C[ta][na])%module)*C[tb][nb])%module;
						q[0].push(ta-na);
						q[1].push(tb-nb);
						q[2].push(tc+na);
						q[3].push(1);
					}else
					if (mp[ta][tb][tc][0]+1==mp[ta-na][tb-nb][tc+na][1])
						mc[ta-na][tb-nb][tc+na][1]=((1LL*((1LL*mc[ta][tb][tc][0]*C[ta][na])%module)*C[tb][nb])%module+mc[ta-na][tb-nb][tc+na][1])%module;
				}
		if (td == 1)
		for (int na=0; na<=tc; na++)
			for (int nb=0; nb<=n-ta-tb-tc; nb++)
				if (na*50 + nb*100 <= k && na+nb>0)
				{
					if (mp[ta+na][tb+nb][tc-na][0]==-1)
					{
						mp[ta+na][tb+nb][tc-na][0]=mp[ta][tb][tc][1]+1;
						mc[ta+na][tb+nb][tc-na][0]=(1LL*((1LL*mc[ta][tb][tc][1]*C[tc][na])%module)*C[n-ta-tb-tc][nb])%module;
						q[0].push(ta+na);
						q[1].push(tb+nb);
						q[2].push(tc-na);
						q[3].push(0);
					}else
					if (mp[ta+na][tb+nb][tc-na][0]==mp[ta][tb][tc][1]+1)
						mc[ta+na][tb+nb][tc-na][0]=((1LL*((1LL*mc[ta][tb][tc][1]*C[tc][na])%module)*C[n-ta-tb-tc][nb])%module+mc[ta+na][tb+nb][tc-na][0])%module;
				}
	}
	if (mp[0][0][c1][1]==-1)
		cout << -1 << endl << 0 << endl;
	else
		cout << mp[0][0][c1][1] << endl << mc[0][0][c1][1] << endl;
	return 0;
}