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
vector<int>son[200005];
bool can[200005];
int fa[200005],depth[200005],good[200005],n,k,tmp,f,t,ans;
void init(int now)
{
	for(int i=0;i<(int)son[now].size();++i)
	{
		if(fa[now]==son[now][i])
		{
			swap(son[now][i],son[now][son[now].size()-1]);
			--i;
			son[now].pop_back();
			continue;
		}
		fa[son[now][i]]=now;
		depth[son[now][i]]=depth[now]+1;
		init(son[now][i]);
		good[now]+=good[son[now][i]];
	}
	if(can[now])
	{
		++good[now];
	}
}
void dfs(int now)
{
	for(int i=0;i<(int)son[now].size();++i)
	{
		ans+=min(good[son[now][i]],(k<<1)-good[son[now][i]]);
		dfs(son[now][i]);
	}
}
signed main(){
	read(n);
	read(k);
	for(int i=1;i<=k<<1;++i)
	{
		read(tmp);
		can[tmp]=true;
	}
	for(int i=1;i<n;++i)
	{
		read(f);
		read(t);
		son[f].push_back(t);
		son[t].push_back(f);
	}
	init(1);
	dfs(1);
	writeln(ans);
	//system("pause");
	return 0;
}