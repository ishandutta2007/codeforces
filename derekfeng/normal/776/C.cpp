#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e9;
int T,n,cnt,K;
ll a[60],cur,ans;
map<ll,int>mp;
void write(ll x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void solve(){
	cnt=0,cur=1,ans=0;
	scanf("%d%d",&n,&K);
	if(K==1)a[++cnt]=1;
	else if(K==-1)a[++cnt]=1,a[++cnt]=-1;
	else while(abs(cur)<=INF*n)a[++cnt]=cur,cur*=K;
	cur=0;
	mp.clear();
	mp[0]++;
	for(int i=1;i<=n;i++){
		scanf("%d",&K);
		cur+=K;
		for(int j=1;j<=cnt;j++)ans+=mp[cur-a[j]];
		mp[cur]++;
	}
	write(ans),puts("");
}
int main(){
	solve();
}