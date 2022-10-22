#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const int M=10;
const ll mod=1000000007ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m;
ll ca[1<<M],cb[1<<M],a[N];
ll mn[1<<M],mna[1<<M],mnb[1<<M];
ll s[N];
int main() {
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		int k;scanf("%d",&k);
		while(k--){
			int x;scanf("%d",&x);
			a[i]+=1<<(x-1);
		}
	}
	s[0]=inf;
	for(i=1;i<=m;i++){
		int k;scanf("%lld%d",&s[i],&k);
		int cnt=0;
		while(k--){
			int x;scanf("%d",&x);
			cnt+=1<<(x-1);
		}
		if(s[i]<s[ca[cnt]]){
			cb[cnt]=ca[cnt];
			ca[cnt]=i;
		}
		else if(s[i]<s[cb[cnt]]) cb[cnt]=i;
	}
	memset(mn,0x3f,sizeof(mn));
	for(i=1;i<(1<<M);i++){
		for(j=1;j<(1<<M);j++){
			int x,y;
			if(i==j&&!cb[j]) continue;
			if(i==j){
				x=ca[i];
				y=cb[i];
			}
			else{
				x=ca[i];
				y=ca[j];
			}
			if(s[x]+s[y]<mn[i|j]){
				mn[i|j]=s[x]+s[y];
				mna[i|j]=x;mnb[i|j]=y;
			}
		}		
	}
	ll ans=0,ansc=inf,ansa=1,ansb=2;
	for(i=0;i<(1<<M);i++){
		int cnt=0;
		if(mn[i]==inf) continue;
		for(j=1;j<=n;j++)
			if((i&a[j])==a[j]) cnt++;
		if(cnt>ans){
			ans=cnt;
			ansc=mn[i];
			ansa=mna[i];ansb=mnb[i];
		}
		else if(cnt==ans){
			if(mn[i]<ansc){
				ansc=mn[i];
				ansa=mna[i];ansb=mnb[i];
			}
		}
	}
	cout<<ansa<<" "<<ansb;
    return 0;
}