#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,N,num[200],f[200];
int a[200005];
ll s,val[200],pre[200];
map<ll,int>mp;
void dfs(ll x){
	if(mp.count(x))return;
	mp[x]=1;
	if(x>1)dfs((x+1)/2),dfs(x/2);
}
void sol(){
	scanf("%d",&n),s=0,mp.clear();
	for(int i=0;i<n;i++)scanf("%d",&a[i]),s+=a[i];
	dfs(s),N=0;
	for(auto it=mp.begin();it!=mp.end();it++)
		it->se=++N,val[N]=it->fi;
	for(int i=1;i<=N;i++)f[i]=num[i]=0;
	for(int i=0;i<n;i++){
		if(!mp.count(a[i])){
			puts("NO");return;
		}
		num[mp[a[i]]]++;
	}
	f[N]=1;
	for(int i=N;i;i--){
		if(f[i]<num[i]){
			puts("NO");return;
		}
		f[i]-=num[i];
		f[mp[val[i]/2]]+=f[i],f[mp[(val[i]+1)/2]]+=f[i];
	}
	puts("YES");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)sol();
}