#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int M=1e9+7;
int n,q;
bool ans[200004];
int c[200004][2];
int mypow(int x,int t){
	int ans=1;
	for(;t;t>>=1,x=(ll)x*x%M)if(t&1)ans=(ll)ans*x%M;
	return ans;
}
bool answer(int N,int D,int s0,int s1){
	int s=(ll)(s0-(ll)c[N-1][0]*D%M+M)%M*mypow(N,M-2)%M;
	int tmp=(((ll)s*s%M*N%M+(ll)s*c[N-1][0]*2%M*D%M)%M+(ll)c[N-1][1]*D%M*D%M)%M;
	return tmp==s1;
}
int a[200004],b[200004],tl,tr;
const int B=450;
int l[200004],r[200004],D[200004];
vector<pii>qr[450];
vector<int>all;
int cnt[200004],s[2],num;
void add(int i){
	int x=all[i];
	cnt[i]++;
	if(cnt[i]==1){
		num++;
		(s[0]+=x)%=M;
		(s[1]+=(ll)x*x%M)%=M;
	}
}
void del(int i){
	int x=all[i];
	cnt[i]--;
	if(cnt[i]==0){
		num--;
		(s[0]+=M-x)%=M;
		(s[1]+=M-(ll)x*x%M)%=M;
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[i][0]=(i+c[i-1][0])%M;
		c[i][1]=((ll)i*i%M+c[i-1][1])%M;
		all.push_back(a[i]);
	}
	sort(all.begin(),all.end());
	for(int i=1;i<=n;i++)b[i]=lower_bound(all.begin(),all.end(),a[i])-all.begin();
	for(int i=1;i<=q;i++)scanf("%d%d%d",&l[i],&r[i],&D[i]),qr[l[i]/B].push_back({r[i],i});
	add(0);
	for(int i=0;i<=n/B;i++)if(!qr[i].empty()){
		sort(qr[i].begin(),qr[i].end());
		for(auto x:qr[i]){
			int j=x.se,L=l[j],R=r[j];
			while(tr<R)++tr,add(b[tr]);
			while(tl<L)del(b[tl]),++tl;
			while(tl>L)--tl,add(b[tl]);
			while(tr>R)del(b[tr]),--tr;
			ans[j]=answer(R-L+1,D[j],s[0],s[1]);
		}
	}
	for(int i=1;i<=q;i++)puts(ans[i]?"Yes":"No");
}