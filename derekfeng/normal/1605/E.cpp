#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
ll a[200004],b[200004];
int tot,mu[200004],pri[200004];
bool flg[200004];
void init(){
	mu[1]=1;
	for(int i=2;i<=2e5;i++){
		if(!flg[i])pri[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&pri[j]*i<=2e5;j++){
			flg[pri[j]*i]=1;
			if(i%pri[j]==0){
				mu[pri[j]*i]=0;
				break;
			}
			mu[pri[j]*i]=-mu[i];
		}
	}
}
ll sum=0;
vector<int>A,B;
ll pA[200004],pB[200004];
ll gotA(ll x){
	int LB=lower_bound(A.begin(),A.end(),x)-A.begin();
	ll ans1=LB*x-pA[LB];
	ll ans2=pA[A.size()]-pA[LB]-(A.size()-LB)*x;
	return ans1+ans2;
}
ll gotB(ll x){
	x=-x;
	int LB=lower_bound(B.begin(),B.end(),x)-B.begin();
	ll ans1=LB*x-pB[LB];
	ll ans2=pB[B.size()]-pB[LB]-(B.size()-LB)*x;
	return ans1+ans2;
}
int main(){
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&b[i]),b[i]-=a[i];
		if(i>1)a[i]=0;
	}
	for(int i=2;i<=n;i++){
		b[i]-=a[i];
		for(int j=i+i;j<=n;j+=i)a[j]+=b[i];
		if(mu[i]==0)sum+=abs(b[i]);
		if(mu[i]==-1)A.push_back(b[i]);
		if(mu[i]==1)B.push_back(b[i]);
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	for(int i=1;i<=A.size();i++)pA[i]=pA[i-1]+A[i-1];
	for(int i=1;i<=B.size();i++)pB[i]=pB[i-1]+B[i-1];
	scanf("%d",&q);
	while(q--){
		ll x;scanf("%lld",&x);x=x-a[1];
		ll ans=sum+abs(x);
		ans+=gotA(x)+gotB(x);
		printf("%lld\n",ans);
	}
}