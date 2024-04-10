#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int mx,mu[N],cnt[N],st[N],tp;bool vis[N];long long ans=1;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int read(){
	int x=0,c;
	while(!isdigit(c=getchar()));
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
vector<int>d[N];
int check(int x){
	int ret=0;
	for(int i:d[x])ret+=mu[i]*cnt[i];
	return ret;
}
void add(int x,int k){for(int i:d[x])cnt[i]+=k;}
int main(){
	for(int n=read(),x;n--;)mx=max(mx,x=read()),vis[x]=1;
	for(int i=1,y;i<=mx;i++){
		for(int j=i;j<=mx;j+=i)
			vis[i]|=vis[j],d[j].push_back(i);
		mu[i]=i^1?(y=i/d[i][1])%d[i][1]?-mu[y]:0:1;
	}
	for(int i=mx,fl=1;i;i--)if(vis[i]){
		int dat=check(i);
		while(dat){
			if(gcd(st[tp],i)==1)
				ans=max(ans,1ll*i*st[tp]),dat--;
			add(st[tp--],-1);fl=0;
		}
		if(fl)add(i,1),st[++tp]=i;
	}
	cout<<ans;
	return 0;
}