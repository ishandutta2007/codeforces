//*
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <string.h>

using namespace std;

#define mp make_pair

typedef long long ll;
typedef pair<ll, ll> pll;

int n, m;
string a[200];
int b[200];
int c[200];

char in[200];

int main()
{
	int i, j, k, l;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		scanf("%s", in);
		a[i]=string(in);
	}
	for(i=0;i<m;i++) scanf("%d", &b[i]), b[i]--, c[b[i]]=1;
	int len=a[b[0]].size();
	for(i=0;i<m;i++)
	{
		if(a[b[i]].size() != len) return !printf("No");
	}
	string ans;
	for(i=0;i<len;i++)
	{
		char u=a[b[0]][i];
		for(j=0;j<m;j++)
		{
			if(a[b[j]][i] != u) u='?';
		}
		ans.push_back(u);
	}
	for(i=0;i<n;i++)
	{
		int mat=1;
		if(a[i].size() != ans.size()) mat=0;
		for(j=0;j<ans.size();j++)
		{
			if(ans[j] == '?') continue;
			if(a[i][j] != ans[j]) mat=0;
		}
		if(mat == 1 && c[i] == 0) return !printf("No");
	}
	printf("Yes\n%s", ans.c_str());
	return 0;
}
//*/