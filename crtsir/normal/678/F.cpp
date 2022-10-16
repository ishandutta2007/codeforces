#include<bits/stdc++.h>
using namespace std;
const int T=1000;
const long long inf=-2333333333333333333;
int n,m;
bool all[300003],nw[300003];
int tp[300003],x[300003],y[300003],idx[300003],mp[300003],Idx[300003],q;
long long ans[300003];
bool cmp(int a,int b){
	if(x[a]!=x[b])
		return x[a]<x[b];
	else
		if(y[a]!=y[b])
			return y[a]<y[b];
		else
			return a<b;
}
int v[300003],sz;
int sm[300003],Sz;
void calc(int l,int r){
	for(int i=0;i<m;i++)
		all[i]=nw[i];
	for(int i=l;i<=r;i++)
		if(tp[i]==2)
			all[mp[x[i]]]=0;
	sz=-1;
	for(int i=0;i<m;i++)
		if(all[i]==1){
			if(sz>=0&&x[idx[i]]==x[idx[v[sz]]])
				sz--;
			while(sz>=1&&1ll*(y[idx[v[sz]]]-y[idx[v[sz-1]]])*(x[idx[v[sz]]]-x[idx[i]])>=1ll*(y[idx[v[sz]]]-y[idx[i]])*(x[idx[v[sz]]]-x[idx[v[sz-1]]]))
				sz--;
			v[++sz]=i;
		}
	Sz=-1;
	for(int i=0;i<m;i++)
		if(all[i]^nw[i])
			sm[++Sz]=idx[i];
	int j=0;q=0;
	for(int i=l;i<=r;i++)
		if(tp[i]==3)
			Idx[q++]=i;
	sort(Idx,Idx+q,cmp);
	for(int i=0;i<q;i++){
		ans[Idx[i]]=inf;
		while(j<sz&&1ll*x[Idx[i]]*x[idx[v[j]]]+y[idx[v[j]]]<=1ll*x[Idx[i]]*x[idx[v[j+1]]]+y[idx[v[j+1]]])j++;
		if(sz!=-1)
			ans[Idx[i]]=max(ans[Idx[i]],1ll*x[Idx[i]]*x[idx[v[j]]]+y[idx[v[j]]]);
	}
	for(int i=l;i<=r;i++){
		if(tp[i]==1){
			nw[mp[i]]=1;
			sm[++Sz]=i;
		}
		if(tp[i]==2)
			nw[mp[x[i]]]=0;
		if(tp[i]==3){
			for(int k=0;k<=Sz;k++)
				if(nw[mp[sm[k]]])
					ans[i]=max(ans[i],1ll*x[i]*x[sm[k]]+y[sm[k]]);
			if(ans[i]==inf)
				printf("EMPTY SET\n");
			else
				printf("%lld\n",ans[i]);
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d%d",tp+i,x+i);
		if(tp[i]==1){
			scanf("%d",y+i);
			idx[m++]=i;
		}
		if(tp[i]==2)
			x[i]--;
	}
	sort(idx,idx+m,cmp);
	for(int i=0;i<m;i++)
		mp[idx[i]]=i;
	for(int i=0;i<n;i+=T)
		calc(i,min(i+T-1,n-1));
}