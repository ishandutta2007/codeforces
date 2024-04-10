#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
const int B=600;
int n,q,a[200005],b[200005];
int l[200005],r[200005],ans[200005];
ll pre[200005];
int tmp[200005];
vector<pair<ll,int> >v;
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i;i--)a[i]-=a[i-1];
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&l[i],&r[i]);
		int pl=(l[i]+B-1)/B,pr=(r[i]+B-1)/B;
		if(pl==pr){
			ll d=0;
			for(int j=l[i]+1;j<=r[i];j++){
				d+=b[j-1];
				(ans[i]+=abs(d)%M*a[j]%M)%=M;
			}
		}else{
			ll d=0;
			for(int j=l[i]+1;j<=pl*B;j++){
				d+=b[j-1];
				(ans[i]+=abs(d)%M*a[j]%M)%=M;
			}
			d=0;
			for(int j=r[i];j>pr*B-B;j--){
				d+=b[j];
				(ans[i]+=abs(d)%M*a[j]%M)%=M;
			}
		}
	}
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+b[i];
	for(int i=1;i<=n;i++)v.push_back({pre[i-1],i});
	sort(v.begin(),v.end());
	for(int t=2;t<(n+B-1)/B;t++){
		int bl=(t-1)*B+1,br=t*B;
		int k=0,b=0;
		for(int i=bl;i<=br;i++)
			(k-=a[i])%=M,(b+=pre[i-1]%M*a[i]%M)%=M;
		for(auto [w,i]:v){
			if(bl<=i&&i<=br){
				(k+=(a[i]+a[i])%M)%=M;
				(b-=pre[i-1]%M*a[i]*2%M)%=M;
			}
			if(i>=bl)continue;
			tmp[i]=((w%M+M)*(k+M)%M+b+M)%M;
		}
		for(int i=1;i<=q;i++)if(l[i]<bl&&br<r[i])(ans[i]+=tmp[l[i]])%=M;
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
}