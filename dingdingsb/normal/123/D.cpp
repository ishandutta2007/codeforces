// 
#include<bits/stdc++.h>
using namespace std;
const int N=100000+100;
int n;char s[N];int c[N],sa[N],x[N],y[N],rk[N],ht[N];
bool cmp(int a,int b,int c){return y[a]==y[b]&&y[a+c]==y[b+c];}
void SA(int m='z'){
	for(int i=0;i<=m;i++)c[i]=0;
	for(int i=1;i<=n;i++)c[x[i]=s[i]]++;
	for(int i=1;i<=m;i++)c[i]+=c[i-1];
	for(int i=n;i>=1;i--)sa[c[x[i]]--]=i;
	for(int k=1;k<=n;k<<=1){
		int num=0;
		for(int i=n-k+1;i<=n;i++)y[++num]=i;
		for(int i=1;i<=n;i++)if(sa[i]>k)y[++num]=sa[i]-k;
		for(int i=0;i<=m;i++)c[i]=0;
		for(int i=1;i<=n;i++)c[x[i]]++;
		for(int i=1;i<=m;i++)c[i]+=c[i-1];
		for(int i=n;i>=1;i--)sa[c[x[y[i]]]--]=y[i],y[i]=0;
		swap(x,y);x[sa[1]]=num=1;
		for(int i=2;i<=n;i++){
			if(cmp(sa[i],sa[i-1],k))x[sa[i]]=num;
			else x[sa[i]]=++num;
		}
		if(num==n)break;m=num;
	}
	for(int i=1;i<=n;i++)rk[sa[i]]=i;
	int k=0;
	for(int i=1;i<=n;i++){
		if(rk[i]==1)continue;
		if(k)k--;
		const int j=sa[rk[i]-1];
		while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k])k++;
		ht[rk[i]]=k;
	}
}
vector<int>add[N];
set<pair<int,int>>st;
signed main(){
	scanf("%s",s+1);n=strlen(s+1);
	SA();
	for(int i=2;i<=n;i++)add[ht[i]].push_back(i);
	st.insert({1,n});
	long long ans=0,now=1ll*n*(n+1)/2;
	for(int i=0;i<n;i++){
		for(auto x:add[i]){
			auto lst=--st.lower_bound({x,0x3f3f3f3f});
			int l=lst->first,r=lst->second;
			now-=1ll*(r-l+1)*(r-l)/2;
			st.erase(lst);
			now+=1ll*(x-1-l+1)*(x-1-l)/2;
			st.insert({l,x-1});
			now+=1ll*(r-x+1)*(r-x)/2;
			st.insert({x,r});
		}
		ans+=now-i;
	}printf("%lld",ans);
	return 0;
}