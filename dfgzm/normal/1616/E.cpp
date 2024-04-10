#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define lowbit(x) (x&-x)
using namespace std;
const int maxn=500005,mod=1000000007;
int T,n;
int tt[maxn];
long long ans;
string s,t,p;
vector<int>v[27];
void update(int x,int v){
	for(int i=x;i<=n;i+=lowbit(i))
		tt[i]+=v;
}
int query(int x){
	int res=0;
	for(int i=x;i;i-=lowbit(i))
		res+=tt[i];
	return res;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),cin>>s>>t,ans=0,p=s;
		sort(p.begin(),p.end());
		if(p>=t){
			puts("-1");
			continue;
		}
		ans=1ll*n*n;
		for(int i=0;i<n;i++)
			v[s[i]-96].push_back(i);
		for(int i=1;i<=26;i++)
			reverse(v[i].begin(),v[i].end());
		long long tot=0;
		for(int i=0;i<n;i++){//lcs
			for(int j=1;j<t[i]-96;j++)
				if(v[j].size())
					ans=min(ans,tot+v[j].back()-query(v[j].back()));
			if(v[t[i]-96].empty())
				break;
			int pos=v[t[i]-96].back();
			tot+=pos-query(pos);
			update(pos+1,1),v[t[i]-96].pop_back();
		}
		printf("%lld\n",ans);
		for(int i=1;i<=26;i++)
			v[i].clear();
		for(int i=1;i<=n;i++)
			tt[i]=0;
	}
	return 0;
}