#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
typedef vector<int> vec;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
int T;
LL suan(LL n){
	if (n==0) return 0;
	LL t=sqrt(n);
	t-=5;
	t=max(t,1ll);
	LL i;
	for (i=t;(i+1)*(i+1)<=n;++i);
	LL ans=(i-1)*3ll+1;
	if (i*i+i<=n) ++ans;
	if (i*i+i+i<=n) ++ans;
	return ans;
}
void doit(){
	long long l,r;
	scanf("%lld%lld",&l,&r);
	long long ans=suan(r)-suan(l-1);
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&T);
	while (T--) doit();
	return 0;
}