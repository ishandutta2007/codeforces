#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
inline LL read()
{
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int n,l,w;
int x,t;
vector<LL> pos,neg;
vector<LL>::iterator it,tmp;
LL ans;
int main()
{
	n=read();l=read();w=read();
	for(int i=1;i<=n;++i){
		x=read();t=read();
		(t==1?pos:neg).pb(x);
	}
	sort(neg.begin(),neg.end());
	for(it=pos.begin();it!=pos.end();++it){
		x=*it;
		if(x>=0){
			if(w>1){
				ans+=neg.end()-upper_bound(neg.begin(),neg.end(),1ll*x*(w+1)/(w-1)-l);
			}
		}
		else{
			t=-x*2/(w+1);
			ans+=neg.end()-upper_bound(neg.begin(),neg.end(),x+t-l);
		}
	}
	printf("%lld",ans);
	return 0;
}