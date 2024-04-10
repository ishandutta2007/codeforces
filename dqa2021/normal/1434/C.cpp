#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long long ll;

void init(){
//	...
}
void solve(){
	ll a=read(),b=read(),c=read(),d=read();
	if (a-c*b>0) return puts("-1"),void();
	ll l=1,r=1e9,mid;
	while (l<r){
		mid=l+r+1>>1;
		if ((mid-1)*d<=c&&-a+(mid-1)*b*d<0) l=mid;
		else r=mid-1;
	}
	ll ans=a*l-l*(l-1)/2*b*d;
	printf("%I64d\n",ans);
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}