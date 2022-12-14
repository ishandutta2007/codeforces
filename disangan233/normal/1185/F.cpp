#include<bits/stdc++.h>
using namespace std;
#define in inline
#define db double
#define ll long long
#define ull unsigned ll
#define re register int
#define ak *
in char getch()
{
	char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
char qwq;
#define gc() getchar()
in int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
const int N=1<<9|233;
int n,m,maxn=-1,ans,ans1,ans2;
int a[N],cnt[N];
vector<pair<int,int> >ve[N];
int main()
{
	n=read(),m=read();
	for(re i=1;i<=n;i++)
	{
		re k=read(),now=0;
		for(re j=1;j<=k;j++) now^=1<<(read()-1);
		a[now]++;	
	}
	for(re i=0;i<(1<<9);i++)
	for(re j=0;j<(1<<9);j++)
	if((i&j)==i) cnt[j]+=a[i];
	for(re i=1;i<=m;i++)
	{
		re v=read(),k=read(),now=0;
		for(re j=1;j<=k;j++) now^=1<<(read()-1);
		ve[now].push_back(make_pair(v,i)); 
	} 
	for(re i=0;i<(1<<9);i++) sort(ve[i].begin(),ve[i].end());
	for(re i=0;i<(1<<9);i++)
	for(re j=0;j<=min(1,(int)ve[i].size()-1);j++) 
	for(re k=0;k<(1<<9);k++)
	for(re t=0;t<=min(1,(int)ve[k].size()-1);t++)
	{
		if(i==k&&j==t) continue;
		if(cnt[i|k]>maxn)
		{
			maxn=cnt[i|k],ans=ve[i][j].first+ve[k][t].first;
			ans1=ve[i][j].second,ans2=ve[k][t].second;
		}
		else if(cnt[i|k]==maxn&&ve[i][j].first+ve[k][t].first<ans)
		ans=ve[i][j].first+ve[k][t].first,ans1=ve[i][j].second,ans2=ve[k][t].second;
	}
	cout<<ans1<<" "<<ans2<<endl;
}