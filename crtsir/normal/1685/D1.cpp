#include<bits/stdc++.h>
using namespace std;
int T,n,p[203],fa[203],ip[203],Fa[203];
int fnd(int x){
	if(fa[x]!=x)fa[x]=fnd(fa[x]);
	return fa[x];
}
void calc(int x){
	cout<<x+1<<' ';
	memcpy(Fa,fa,sizeof(Fa));
	int l,r;
	for(r=x+1;r<n;r++)
		if(fnd(r-1)!=fnd(r))
			fa[fnd(r)]=fnd(r-1);
		else
			break;
	r--;
	memcpy(fa,Fa,sizeof(Fa));
	for(l=x-1;l>0;l--)
		if(fnd(l)!=fnd(l+1))
			fa[fnd(l)]=fnd(l+1);
		else
			break;
	l++;
	memcpy(fa,Fa,sizeof(Fa));
	if(l==r&&ip[x]==0)return;
	int j=-1;
	for(int i=l;i<=r;i++)
		if(ip[i]&&(j==-1||ip[j]>ip[i]))
			j=i;
	for(int i=j;i>x;i--)
		if(fnd(i-1)!=fnd(i))
			swap(ip[i],ip[i-1]),
			fa[fnd(i)]=fnd(i-1);
	for(int i=j;i<x;i++)
		if(fnd(i+1)!=fnd(i))
			swap(ip[i],ip[i+1]),
			fa[fnd(i)]=fnd(i+1);
	calc(ip[x]);
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>p[i],p[i]--,fa[i]=i,ip[p[i]]=i;
		for(int i=0;i<n;i++)
			fa[fnd(i)]=fnd(p[i]);
		for(int i=1;i<n;i++)
			if(fnd(i-1)!=fnd(i))
				swap(ip[i],ip[i-1]),
				fa[fnd(i)]=fnd(i-1);
		calc(0);
		cout<<endl;
	}
}