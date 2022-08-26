#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
string st;
int jy[201][101][50][2],n,m,i,j,ma;
int dfs(int wz,int i,int zls,bool zheng)
{
	//cerr<<"dfs("<<wz<<' '<<i<<' '<<zls<<' '<<zheng<<")\n";
	if (zls<0||(zls>0&&i>=st.length())) return 0;
	if (i>=st.length()) return abs(wz);
	if (jy[wz+100][i][zls][zheng]!=-1) return jy[wz+100][i][zls][zheng];
	return jy[wz+100][i][zls][zheng]=max(dfs(wz+(int(zheng))*2-1,i+1,zls-(st[i]!='F'),zheng),dfs(wz,i+1,zls-(st[i]=='F'),!zheng));
}
int main()
{
	memset(jy,-1,sizeof(jy));
	cin>>st>>n;
	for (i=n;i>-1;i-=2)
	{
		ma=max(ma,dfs(0,0,i,1));
	}
	cout<<ma;
	return 0;
}