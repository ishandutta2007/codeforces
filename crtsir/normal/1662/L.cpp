#include<bits/stdc++.h>
using namespace std;
long long x[200003],y[200003];
int n,v,idx[200003];
bool cmp(int a,int b){
	if(x[a]!=x[b])return x[a]<x[b];
	return y[a]<y[b];
}
int dat[200003];
int query(int x){
	int ret=-233333;
	while(x){
		ret=max(dat[x],ret);
		x-=(x&-x);
	}return ret;
}
void add(int x,int y){
	while(x<200003){
		dat[x]=max(dat[x],y);
		x+=(x&-x);
	}
}
int main(){
	cin>>n>>v;
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		x[i]=1ll*v*t;
		y[i]=x[i];
		idx[i]=i;
	}
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		x[i]-=a;
		y[i]+=a;
	}
	vector<long long>v;
	for(int i=0;i<=n;i++)
		v.push_back(y[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	map<long long,int>mp;
	for(int i=0;i<v.size();i++)
		mp[v[i]]=i+1;
	sort(idx,idx+n+1,cmp);
	memset(dat,192,sizeof(dat));
	for(int i=0;i<=n;i++)
		if(x[idx[i]]==0&&y[idx[i]]==0)
			add(mp[0],0);
		else
			add(mp[y[idx[i]]],1+query(mp[y[idx[i]]]));
	cout<<query(200002);
}