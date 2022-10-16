#include<bits/stdc++.h>
using namespace std;
int n,a[100003],invmp[100003],m,b[100003],dp[100003],lst[100003];
pair<int,int>f[100003];
map<int,int>mp;
vector<int>v;
multiset<int>st;
pair<int,int>dat[262144];
int pa[100003];
void add(int k,pair<int,int>x){
	k+=131072;
	while(k){
		dat[k]=max(dat[k],x);
		k>>=1;
	}
}
pair<int,int>query(int l,int r,int _l,int _r,int k){
	if(l<=_l&&_r<=r)return dat[k];
	if(l>_r||r<_l)return make_pair(0,0);
	return max(query(l,r,_l,_l+_r>>1,k<<1),query(l,r,_l+_r+1>>1,_r,k<<1|1)); 
}
int ans[100003];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]!=-1)v.push_back(a[i]);
	}
	for(int i=2;i<=n+1;i++)
		if(a[i-1]!=-1)
			lst[i]=lst[i-1];
		else
			lst[i]=i-1;
	cin>>m;
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<v.size();i++){
		mp[v[i]]=i+1;
		invmp[i+1]=v[i];
	}
	for(int i=1;i<=n;i++)
		if(a[i]!=-1)
			a[i]=mp[a[i]];
	v.clear();
	for(int i=0;i<m;i++){
		scanf("%d",b+i);
		st.insert(b[i]);
		v.push_back(b[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	m=v.size();
	for(int i=0;i<m;i++)
		b[i]=v[i];
	for(int i=1;i<=n;i++)
		if(a[i]!=-1){
			f[i]=query(0,a[i]-1,0,131071,1);
			f[i].first++;
			int l=0,r=m,mid;
			while(l!=r){
				mid=(l+r>>1);
				if(b[mid]>=invmp[a[i]])
					r=mid;
				else
					l=mid+1;
			}
			if(l)f[i]=max(f[i],make_pair(dp[l-1]+1,lst[i]));
			add(a[i],make_pair(f[i].first,i));
		}
		else{
			for(int j=m-1;j>0;j--)
				dp[j]=max(dp[j],dp[j-1]+1);
			for(int j=0,k=0,maxn=0;j<m;j++){
				while(k<=n&&invmp[k]<b[j]){
					maxn=max(maxn,dat[131072|k].first+1); 
					k++;
				}
				dp[j]=max(maxn,dp[j]);
			}
		}
	pair<int,int>res=dat[1];
	for(int i=0;i<m;i++)
		res=max(res,make_pair(dp[i],lst[n+1]));
	int nw=res.second,val=res.first,Lst=1000000007;
	for(int i=1;i<=n;i++)
		if(a[i]!=-1)
			a[i]=invmp[a[i]];
	while(nw){
		if(a[nw]!=-1)
			Lst=a[nw],
			nw=f[nw].second,
			val--;
		else{
			for(int j=m-1;j>=0;j--)
				if(b[j]<Lst){
					a[nw]=b[j];
					st.erase(st.find(a[nw]));
					break;
				}
			Lst=a[nw];
			bool ok=0;
			for(int j=0;j<nw;j++)
				if(a[j]!=-1&&f[j].first==val-1&&a[j]<Lst){
					nw=j;
					val--;
					ok=1;
					break;
				}
			if(ok)continue;
			nw=lst[nw];
			val--;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==-1){
			a[i]=(*st.begin()),
			st.erase(st.begin());
		}
		printf("%d ",a[i]);
	}
}