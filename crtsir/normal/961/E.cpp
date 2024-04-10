#include<bits/stdc++.h>
using namespace std;
int bit[200003],n,a[200003];
long long ans;
vector<int>v[200003];
void add(int x,int a){
	while(x<=n)bit[x]+=a,x=x+(x&-x);
}
int query(int x){
	int ret=0;
	while(x)ret+=bit[x],x=x-(x&-x);
	return ret;
}
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=i)ans--;
		if(a[i]<=n)
			v[a[i]].push_back(i);
		add(i,1);
	}
	for(int i=1;i<=n;i++){
		int x=min(n,a[i]);
		ans+=query(x);
		for(int j=0;j<v[i].size();j++)
			add(v[i][j],-1);
	}
	cout<<ans/2;
}