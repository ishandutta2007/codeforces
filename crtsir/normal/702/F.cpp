#include<bits/stdc++.h>
using namespace std;
int n,m,v[200003],b[200003],nw[200003],_sum[200003],nxt[200003],idx[200003],val[200003],tmp[200003],ans[200003];
pair<int,int>t[200003];
long long sum[200003];
bool cmp(int x,int y){
	return nw[x]>nw[y];
}
int dat[200003];
void add(int x,int y){
	while(x<=n){
		dat[x]=min(dat[x],y);
		x+=(x&-x);
	}
}
int query(int x){
	int ret=998244353;
	while(x){
		ret=min(ret,dat[x]);
		x^=(x&-x);
	}return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&t[i].second,&t[i].first),
		t[i].first=-t[i].first;
	sort(t,t+n);
	for(int i=0;i<n;i++)
		v[i]=t[i].second;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
		scanf("%d",b+i),idx[i]=i;
	for(int i=29;i>=0;i--){
		for(int j=0;j<n;j++){
			if(v[j]<(1<<i))
				sum[j+1]=v[j],_sum[j+1]=1;
			else
				sum[j+1]=0,_sum[j+1]=0;
			sum[j+1]+=sum[j];
			_sum[j+1]+=_sum[j];
		}
		for(int j=0;j<m;j++){
			int l=nw[j],r=n;
			while(l!=r){
				int mid=(l+r>>1);
				if(b[j]+sum[nw[j]]-sum[mid]<(1<<i))
					r=mid;
				else
					l=mid+1;
			}nxt[j]=l;tmp[j]=_sum[l]-_sum[nw[j]];
		}
		vector<long long>g;
		for(int j=0;j<n;j++)
			if((1<<i)<=v[j]&&v[j]<(1<<i+1))
				g.push_back(sum[j+1]+v[j]);
		sort(g.begin(),g.end());
		g.erase(unique(g.begin(),g.end()),g.end());
		set<pair<long long,int> >st;
		for(int j=0;j<g.size();j++)
			st.insert({-g[j],j+1});
		for(int j=0;j<n;j++)
			if((1<<i)<=v[j]&&v[j]<(1<<i+1))
				val[j]=(*st.lower_bound({-v[j]-sum[j+1],-1})).second;
			else
				val[j]=-1;
		sort(idx,idx+m,cmp);
		memset(dat,31,sizeof(dat));
		for(int j=0,k=n-1;j<m;j++){
			while(k>=nw[idx[j]]){
				if(val[k]!=-1)
					add(val[k],k);
				k--;
			}
			if(st.lower_bound({-b[idx[j]]-sum[nw[idx[j]]],-1})==st.end())
				continue;
			int T=query((*st.lower_bound({-b[idx[j]]-sum[nw[idx[j]]],-1})).second);
			if(T<nxt[idx[j]]){
				nxt[idx[j]]=T;
				tmp[idx[j]]=_sum[nxt[idx[j]]]-_sum[nw[idx[j]]]+1;
				b[idx[j]]-=v[nxt[idx[j]]];
			}
		}
		for(int j=0;j<m;j++){
			b[j]-=sum[nxt[j]]-sum[nw[j]];
			nw[j]=nxt[j],ans[j]+=tmp[j];
		}
	}
	for(int j=0;j<m;j++)
		printf("%d ",ans[j]);
}