#include<bits/stdc++.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define N 200000
using namespace std;
int n,Q,del[N+5];
struct clothes
{
	int a,b,pos,Price;
	bool operator < (const clothes a) const
	{
		return Price>a.Price;
	}
}s[N+5];
priority_queue<clothes> h[4];
inline char tc()
{
	static char ff[100000],*A=ff,*B=ff;
	return A==B&&(B=(A=ff)+fread(ff,1,100000,stdin),A==B)?EOF:*A++;
}
inline void read(int &x)
{
	x=0;char ch;
	while(!isdigit(ch=tc()));
	while(x=(x<<3)+(x<<1)+ch-'0',isdigit(ch=tc()));
}
inline void write(int x)
{
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
bool cmp(clothes x,clothes y)
{
	return x.Price<y.Price;
}
int main()
{
//	freopen("a.in","r",stdin);
	register int i;
	for(read(n),i=1;i<=n;++i) read(s[i].Price);
	for(i=1;i<=n;++i) read(s[i].a),s[i].pos=i;
	for(i=1;i<=n;++i) read(s[i].b),h[s[i].a].push(s[i]),h[s[i].b].push(s[i]);
	for(read(Q);Q;--Q)
	{
		int x;read(x);
		while(!h[x].empty()&&del[h[x].top().pos]) h[x].pop();
		if(h[x].empty()) putchar('-'),putchar('1'),putchar(' ');
		else write(h[x].top().Price),putchar(' '),del[h[x].top().pos]=1,h[x].pop();
	}
	return 0;
}