#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200005
int T, n, m, a[N], b[N], sta, stb, ok[N], ans, cl, cr;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; ++i) scanf("%d", a+i), ok[i]=0;
		for(int i=1; i<=m; ++i) scanf("%d", b+i);
		a[n+1]=b[m+1]=0;
		ans=cl=cr=0;
		for(int i=1, l=1; i<=n; ++i)
		{
			while(l<=m&&b[l]<a[i]) ++l;
			if(a[i]==b[l]) ok[i]=1, ++ans;
		}
		sta=stb=1;
		while(a[sta]<0) ++sta;
		while(b[stb]<0) ++stb;
		for(int i=stb, r=stb, cur=0, len=0; i<=m; ++i)
		{
			while(sta+len<=n&&a[sta+len]<=b[i]+len) cur+=ok[sta+len], ++len;
			while(r<=m&&b[r]<=b[i]+len-1) ++r;
//			printf("fa %d %d %d\n", i, r, len);
			cr=std::max(cr, r-i-cur);
//			printf("fa %d %d %d\n", i, r, len);
		}
		for(int i=stb-1, r=stb-1, cur=0, len=0; i; --i)
		{
			while(sta-len-1&&a[sta-len-1]>=b[i]-len) cur+=ok[sta-len-1], ++len;
			while(r&&b[r]>=b[i]-len+1) --r;
			cl=std::max(cl, i-r-cur);
		}
//		printf("%d %d %d\n", ans, cl, cr);
		printf("%d\n", ans+cl+cr);
	}
	return 0;
}