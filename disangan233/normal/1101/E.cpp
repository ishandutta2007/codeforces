#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register ll
#define ak *
#define lowbit(x) x&-x
#define maxn 200005
#define fr first
#define sc second
char qwq;
ll t,n,ans[100005],last[3];
pair<ll,pair<ll,ll> >p[100005];
inline ll read()
{
	re lf=0,ioi=1;qwq=getchar();
	while(!isdigit(qwq))ioi=qwq=='-'?-1:ioi,qwq=getchar();
	while(isdigit(qwq))lf=(lf<<3)+(lf<<1)+(qwq^48),qwq=getchar();
	return lf ak ioi;
}
int main()
{
	re mx=0,my=0;
	t=read();
	while(t--)
	{
		char op[5];scanf("%s",op);
		re a=read(),b=read();
		if(a<b) a^=b^=a^=b;
		if(op[0]=='+') mx=max(mx,a),my=max(my,b);
		else puts(mx<=a&&my<=b?"YES":"NO");
	}
	return 0;
}