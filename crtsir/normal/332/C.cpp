#include<bits/stdc++.h>
using namespace std;
int n,p,k,a[100003],b[100003],x[100003];
bool vis[100003];vector<int>v;
bool cmp1(int f,int s){
	if(b[f]!=b[s])return b[f]<b[s];
	return a[f]>a[s];
}
bool cmp2(int f,int s){
	if(a[f]!=a[s])return a[f]>a[s];
	return b[f]>b[s];
}
bool cmp3(int f,int s){
	return b[f]>b[s];
}
int main(){
	cin>>n>>p>>k;
	for(int i=0;i<n;i++)scanf("%d%d",&a[i],&b[i]),x[i]=i;
	sort(x,x+n,cmp1);
	sort(x+p-k,x+n,cmp2);
	pair<int,int>minn=make_pair(2147483647,0);
	for(int i=p-k;i<p;i++){
		minn=min(minn,make_pair(b[x[i]],-a[x[i]]));
		cout<<x[i]+1<<' ',vis[x[i]]=1;
	}
	for(int i=0;i<n;i++)
		if(!vis[i]&&minn>=make_pair(b[i],-a[i]))
			v.push_back(i);
	sort(v.begin(),v.end(),cmp3);
	for(int i=0;i<p-k;i++)cout<<v[i]+1<<' ';
}