#include<bits/stdc++.h>
#define LL long long
#define pb push_back
using namespace std;
const int N=1e6+50;
int n,a[N];LL S,ans=1e18;
void upd(LL x){
	if(x==1)return;
	LL ret=0,now=0;
	for(int i=1;i<n;i++){
		now+=a[i];now%=x;
		ret+=min(now,x-now);
		if(ret>=ans)return;
	}//cout<<x<<" "<<ret<<endl;
	ans=ret;
}
vector<LL>v;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),S+=a[i];
	for(int i=2;1ll*i*i<=S;i++)
		if(S%i==0){
			v.pb(i);
			while(S%i==0)S/=i;
		}
	if(S!=1)v.pb(S);
	random_shuffle(v.begin(),v.end());
	for(int i=0;i<v.size();i++)upd(v[i]);
	cout<<(ans==1e18?-1:ans);
	return 0;
}