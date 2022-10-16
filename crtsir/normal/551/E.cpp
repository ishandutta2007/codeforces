#include<bits/stdc++.h>
using namespace std;
long long n,T,a[500003],pl[1003],lth,l,r,x,i;
vector<pair<long long,long long> >v[1003];
void Plus(){
	scanf("%lld%lld%lld",&l,&r,&x);l--;r--;
	for(i=0;i<v[l/lth].size();i++)if(v[l/lth][i].second<=r&&l<=v[l/lth][i].second)v[l/lth][i].first+=x;
	sort(v[l/lth].begin(),v[l/lth].end());
	if(l/lth!=r/lth){
		for(i=l/lth+1;i<r/lth;i++)pl[i]+=x;
		for(i=0;i<v[r/lth].size();i++)if(v[r/lth][i].second<=r&&l<=v[r/lth][i].second)v[r/lth][i].first+=x;
		sort(v[r/lth].begin(),v[r/lth].end());
	}
}
long long smallfind(long long now,long long x){
	for(i=0;i<v[now].size();i++)if(v[now][i].first==x)return v[now][i].second;
	return -2147000000;
}
long long bigfind(long long now,long long x){
	for(i=v[now].size()-1;i>=0;i--)if(v[now][i].first==x)return v[now][i].second;
	return -2147000000;
}
bool find(long long now,long long x){
	long long l=0,r=v[now].size()-1;
	if(v[now][0].first>x)return 0;
	while(l!=r){
		long long mid=(l+r)/2;
		if(v[now][mid].first>x)
			r=mid-1;
		else
			l=mid;
		if(v[now][l+1].first<=x)l++;
		if(v[now][r].first>x)r--;
	}
	if(v[now][l].first==x)return 1;else return 0;
}
long long Find(){
	scanf("%lld",&x);
	for(l=0;l<(n+lth-1)/lth&&!find(l,x-pl[l]);l++);
	if(l==(n+lth-1)/lth)return -1;
	for(r=(n-1)/lth;r>=0&&!find(r,x-pl[r]);r--);
	long long lmst=smallfind(l,x-pl[l]),rmst=bigfind(r,x-pl[r]);
	return rmst-lmst;
}
int main(){
	scanf("%lld%lld",&n,&T);lth=505;
	for(long long i=0;i<n;i++)scanf("%lld",a+i),v[i/lth].push_back(make_pair(a[i],i));
	for(long long i=0;i<n;i+=lth)sort(v[i/lth].begin(),v[i/lth].end());
	while(T--){
		long long type;scanf("%d",&type);
		if(type==1)Plus();
		else cout<<Find()<<endl;
	} 
}