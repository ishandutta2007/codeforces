#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
int n,l[100004],r[100004],num;
int mch[200004],id[200004],bit[200004];
void upd(int i){for(;i;i-=i&-i)bit[i]++;}
int qry(int i){int ans=0;for(;i<=n+n;i+=i&-i)ans+=bit[i];return ans;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int L,R;scanf("%d%d",&L,&R);if(L>R)swap(L,R);
		mch[L]=R,id[L]=i,mch[R]=-L,id[R]=i;
	}
	for(int i=1;i<=n+n;i++){
		if(mch[i]>0)l[id[i]]=num+qry(mch[i]),upd(mch[i]);
		else num++;
	}
	num=0,memset(bit,0,sizeof(bit));
	for(int i=n+n;i;i--){
		if(mch[i]>0)num++,r[id[i]]=qry(i)-qry(mch[i]),upd(mch[i]);
		else l[id[i]]+=num;
	}
	for(int i=1;i<=n;i++)ans+=(ll)(l[i]+r[i])*(n-1-l[i]-r[i])+(ll)l[i]*r[i]*2;ans/=2;
	printf("%lld\n",(ll)n*(n-1)*(n-2)/6-ans);
}