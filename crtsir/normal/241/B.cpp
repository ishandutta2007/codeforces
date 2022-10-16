#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,m,a[50003];
int ls[1500003],rs[1500003],rt,N,mp[1500003],sz[1500003];
int cnt[33][100003],M;
int add(int k,int p,int val){
	if(k==0)
		k=++N;
	sz[k]++;
	if(p==-1)
		return k;
	if(!(val&(1<<p)))
		ls[k]=add(ls[k],p-1,val);
	else
		rs[k]=add(rs[k],p-1,val);
	return k;
}
void calc(int k,int val){
	if(ls[k])calc(ls[k],val<<1);
	if(rs[k])calc(rs[k],val<<1|1);
	if(!ls[k]&&!rs[k]){
		mp[k]=++M;
		for(int i=0;i<30;i++)
			if(val&(1<<i))
				cnt[i][M]=sz[k];
	}else if(ls[k]&&rs[k]){
		mp[k]=++M;
		for(int i=0;i<30;i++)
			cnt[i][M]=cnt[i][mp[ls[k]]]+cnt[i][mp[rs[k]]];
	}else if(ls[k])
		mp[k]=mp[ls[k]];
	else
		mp[k]=mp[rs[k]];
}
vector<pair<int,int> >nw,tmp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		rt=add(rt,29,a[i]);
	}
	calc(rt,0);
	nw.push_back({rt,rt});
	long long ans=0;
	int val=0;
	for(int i=29;i>=0;i--){
		tmp.clear();
		int sum=0;
		for(int j=0;j<nw.size();j++){
			int x=nw[j].first,y=nw[j].second;
			sum+=sz[ls[x]]*sz[rs[y]];
			if(x!=y)sum+=sz[rs[x]]*sz[ls[y]];
		}
		if(sum<=m){
			m-=sum;
			for(int j=0;j<nw.size();j++){
				int x=nw[j].first,y=nw[j].second;
				if(ls[x]&&ls[y])
					tmp.push_back({ls[x],ls[y]});
				if(rs[x]&&rs[y])
					tmp.push_back({rs[x],rs[y]});
				if(ls[x]&&rs[y])
					for(int k=0;k<30;k++)
						ans+=(1ll<<k)*(cnt[k][mp[ls[x]]]*(sz[rs[y]]-cnt[k][mp[rs[y]]])+(sz[ls[x]]-cnt[k][mp[ls[x]]])*cnt[k][mp[rs[y]]]);
				if(rs[x]&&ls[y]&&x!=y)
					for(int k=0;k<30;k++)
						ans+=(1ll<<k)*(cnt[k][mp[rs[x]]]*(sz[ls[y]]-cnt[k][mp[ls[y]]])+(sz[rs[x]]-cnt[k][mp[rs[x]]])*cnt[k][mp[ls[y]]]);
			}
		}else{
			val|=(1<<i);
			for(int j=0;j<nw.size();j++){
				int x=nw[j].first,y=nw[j].second;
				if(ls[x]&&rs[y])
					tmp.push_back({ls[x],rs[y]});
				if(x!=y)
					if(rs[x]&&ls[y])
						tmp.push_back({rs[x],ls[y]});
			}
		}
		nw=tmp;
	}
	cout<<(ans+1ll*m*val)%mod;
}