#include<bits/stdc++.h>
/* Chinese_zjc_ */
#define RT register
#define int long long
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f)x=-x;return x;
}
template<class t>inline void write(t x){
	if(x<0)putchar('-'),write(-x);
	else{if(x>9)write(x/10);putchar('0'+x%10);}
}
template<class t>inline void writeln(t x){
	write(x);putchar('\n');
	return;
}
template<class t>inline void write_blank(t x){
	write(x);putchar(' ');
	return;
}
int n,m,q,a[300005],b[300005],c[300005],ans[300005],sum;
bitset < 10005 > g[10005],all1,all0;
vector < int > nxt[300005];
void dfs(int now)
{
	bool worked=false;
	if(a[now]==1)
	{
		if(!g[b[now]][c[now]])
		{
			g[b[now]][c[now]]=true;
			++sum;
			worked=true;
		}
	}
	if(a[now]==2)
	{
		if(g[b[now]][c[now]])
		{
			g[b[now]][c[now]]=false;
			--sum;
			worked=true;
		}
	}
	if(a[now]==3)
	{
		sum=sum+m-(g[b[now]].count()<<1);
		g[b[now]]^=all1;
	}
//	cout<<now<<endl;
//	for(int i=1;i<=n;++i)
//	{
//		for(int j=1;j<=m;++j)
//		{
//			cout<<g[i][j];
//		}
//		cout<<endl;
//	}
	ans[now]=sum;
	for(int i=0;i<(int)nxt[now].size();++i)
	{
		dfs(nxt[now][i]);
	}
	if(a[now]==1)
	{
		if(worked)
		{
			g[b[now]][c[now]]=false;
			--sum;
		}
	}
	if(a[now]==2)
	{
		if(worked)
		{
			g[b[now]][c[now]]=true;
			++sum;
		}
	}
	if(a[now]==3)
	{
		g[b[now]]^=all1;
		sum=sum-m+(g[b[now]].count()<<1);
	}
}
signed main(){
	read(n);
	read(m);
	read(q);
	for(int i=1;i<=m;++i)
	{
		all1[i]=true;
	}
	for(int i=1;i<=q;++i)
	{
		read(a[i]);
		if(a[i]==1)
		{
			read(b[i]);
			read(c[i]);
		}
		if(a[i]==2)
		{
			read(b[i]);
			read(c[i]);
		}
		if(a[i]==3)
		{
			read(b[i]);
		}
		if(a[i]==4)
		{
			read(b[i]);
			nxt[b[i]].push_back(i);
		}
		else
		{
			nxt[i-1].push_back(i);
		}
	}
	for(int i=0;i<(int)nxt[0].size();++i)
	{
		dfs(nxt[0][i]);
	}
	for(int i=1;i<=q;++i)
	{
		writeln(ans[i]);
	}
	//system("pause");
	return 0;
}