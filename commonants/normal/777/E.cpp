#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
#define lbt(i) ((i)&(-(i)))

using namespace std;
typedef long long LL;
const LL MX=400100;

struct R{
	LL a,b;LL h;
	void rd(){scanf("%I64d%I64d%I64d",&a,&b,&h);}
}r[MX];
LL n;
LL v[MX],f[MX];LL mx;
set<LL>tmp;
map<LL,LL>F;
bool cmp(R x,R y){
	return x.b<y.b||(x.b==y.b&&x.a<y.a);
}
LL que(LL k){
	LL ans=0;for(LL i=k;i;i-=lbt(i))ans=max(ans,v[i]);
	return ans;
}
void upd(LL k,LL va){
	for(LL i=k;i<=mx;i+=lbt(i))v[i]=max(v[i],va);
}
void disc(){
	for(LL i=1;i<=n;i++)tmp.insert(r[i].a),tmp.insert(r[i].b);
	for(set<LL>::iterator it=tmp.begin();it!=tmp.end();it++)F[*it]=++mx;
	for(LL i=1;i<=n;i++)r[i].a=F[r[i].a],r[i].b=F[r[i].b];
}
int main()
{
	scanf("%I64d",&n);
	for(LL i=1;i<=n;i++)
	r[i].rd();
	disc();
	sort(r+1,r+n+1,cmp);
	for(LL i=n;i>=1;i--)upd(r[i].a+1,f[i]=que(r[i].b)+r[i].h);
	LL ans=0;
	for(LL i=1;i<=n;i++)ans=max(ans,f[i]);
	printf("%I64d\n",ans);
	return 0;
}