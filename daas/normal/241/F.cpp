#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,K,val[110][110];
pair<int,int> pos[110];
char s[1010];
int Move(pair<int,int> st,pair<int,int> ed)
{
	int wx,wy;
	if(st.first==ed.first) wx=0,wy=(st.second<ed.second?1:-1);
	else wx=(st.first<ed.first?1:-1),wy=0;
	while((st.first!=ed.first || st.second!=ed.second) && K>=val[st.first][st.second])
	{
		K-=val[st.first][st.second];
		st.first+=wx;
		st.second+=wy;
	}
	if(st.first==ed.first && st.second==ed.second) return 1;
	printf("%d %d\n",st.first,st.second);
	return 0;
}
int main()
{
	n=read(),m=read(),K=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)
		{
			if('a'<=s[j] && s[j]<='z') pos[s[j]-'a']=make_pair(i,j),val[i][j]=1;
			if('0'<=s[j] && s[j]<='9') val[i][j]=s[j]-'0';
		}
	}
	pair<int,int> S,T,x;
	S.first=read(),S.second=read();
	x=S;
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;++i)
	{
		int id=s[i]-'a';
		int val=Move(x,pos[id]);
		if(val) x=pos[id];
		else return 0;
	}
	T.first=read(),T.second=read();
	int val=Move(x,T);
	if(val) printf("%d %d\n",T.first,T.second);
	return 0;
}
//ore no turn,draw