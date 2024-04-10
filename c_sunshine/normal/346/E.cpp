#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
int T,a,n,p,h,ans;

int work(LL a,LL n,LL p)
{
	LL c=a*n/p;
	if(!c)return max(a,p-a*n);
	if(a*n%p<a*(p/a-1))c--;
	return work(min(a-p%a,p%a),c,a);
}

int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d%d%d",&a,&n,&p,&h);a%=p;
		ans=(LL)a*n<p?a:work(a,n,p);
		puts(h<ans?"NO":"YES");
	}
	return 0;
}