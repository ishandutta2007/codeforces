#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2.5e5 + 5;

int n,m;
vector<int> a[MAXN], dif[MAXN];

inline vector<int> get_dif(const vector<int> &a,const vector<int> &b,int fob = -1)
{
	vector<int> res;
	for(int i=0; i<(int)a.size(); ++i)
		if(i != fob && a[i] != b[i]) res.push_back(i);
	return res;
}

inline bool chk0(void)
{
	for(int i=2; i<=n; ++i)
		if(get_dif(a[1], a[i]).size() > 2) return 0;
	return 1;
}

inline bool chk1(int p)
{
	int k = -1;
	for(int i=2; i<=n; ++i)
	{
		int need = get_dif(a[1], a[i], p).size();
		if(need > 2) return 0;
		if(need < 2) continue;
		if(k != -1 && k != a[i][p]) return 0;
		k = a[i][p];
	}
	if(k != -1) a[1][p] = k;
	return 1;
}

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		a[i].resize(m);
		for(int j=0; j<m; ++j) scanf("%d",&a[i][j]);
	}
	
	int pos = 2;
	for(int i=2; i<=n; ++i)
	{
		dif[i] = get_dif(a[1] ,a[i]);
		if(dif[i].size() > 4) return printf("No"), 0;
		if(dif[i].size() > dif[pos].size()) pos = i;
	}
	
	if(dif[pos].size() <= 2)
	{
		printf("Yes\n");
		for(int i=0; i<m; ++i) printf("%d ",a[1][i]);
		return 0;
	}
	if(dif[pos].size() == 4)
	{
		vector<int> &vec = dif[pos];
		for(int i=0; i<4; ++i)
			for(int j=0; j<i; ++j)
			{
				int x = a[1][vec[i]], y = a[1][vec[j]];
				a[1][vec[i]] = a[pos][vec[i]];
				a[1][vec[j]] = a[pos][vec[j]];
				
				if(chk0())
				{
					printf("Yes\n");
					for(int i=0; i<m; ++i) printf("%d ",a[1][i]);
					return 0;
				}
				
				a[1][vec[i]] = x; a[1][vec[j]] = y;
			}
		return printf("No"), 0;
	}
	
	vector<int> &vec = dif[pos];
	for(int i=0; i<3; ++i)
	{
		int x = a[1][vec[i]];
		a[1][vec[i]] = a[pos][vec[i]]; 
		for(int j=0; j<3; ++j)
			if(j != i && chk1(vec[j]))
			{
				printf("Yes\n");
				for(int i=0; i<m; ++i) printf("%d ",a[1][i]);
				return 0;
			}
		a[1][vec[i]] = x;
	}
	
	printf("No");
	return 0;
}