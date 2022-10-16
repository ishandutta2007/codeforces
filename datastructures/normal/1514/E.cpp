#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int t,n;
vector<int> id;
int dsu[105];
int c[105][105];
int dsu_find(int x){
	if (x==dsu[x])return x;
	return dsu[x]=dsu_find(dsu[x]);
}
int ask1(int x,int y){
	cout<<1<<' '<<x<<' '<<y<<endl;
	fflush(stdout);
	int fg;
	cin>>fg;
	return fg;
}
int ask2(int x,int r){
	cout<<2<<' '<<x<<' '<<r+1<<' ';
	for (int i=0;i<=r;i++)cout<<id[i]<<' ';
	cout<<endl;
	fflush(stdout);
	int fg;
	cin>>fg;
	return fg;
}
vector<int> vec_merge(vector<int> a,vector<int> b){
	vector<int> c;
	int p1=0,p2=0;
	int l1=a.size(),l2=b.size();
	while(p1<l1&&p2<l2){
		if (ask1(a[p1],b[p2])==1){
			c.push_back(a[p1]);
			p1++;
		}
		else{
			c.push_back(b[p2]);
			p2++;
		}
	}
	while(p1<l1)c.push_back(a[p1]),p1++;
	while(p2<l2)c.push_back(b[p2]),p2++;
	return c;
}
vector<int> solve(int l,int r){
	vector<int> ans;
	if (l==r){
		ans.push_back(l);
		return ans;
	}
	int mid=(l+r)/2;
	ans=vec_merge(solve(l,mid),solve(mid+1,r));
	return ans;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		id=solve(0,n-1);
		for (int i=0;i<n;i++)dsu[i]=i;
		int p=n-1;
		for (int i=n-1;i>=0;i--){
			p=min(p,i);
			while(p>0&&ask2(id[i],p-1)){
				p--;
				dsu[dsu_find(id[i])]=dsu[id[p]];
			}
		}
		for (int i=0;i<n;i++){
			if (id[i]==dsu_find(id[i]))
				for (int j=i;j<n;j++)c[id[i]][id[j]]=1;
			else for (int j=0;j<n;j++)c[id[i]][j]=c[dsu_find(id[i])][j];
		}
		cout<<3<<endl;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++)cout<<c[i][j];
			cout<<endl;
		}
		int fg;
		cin>>fg;
		memset(c,0,sizeof(c));
	}
	return 0;
}