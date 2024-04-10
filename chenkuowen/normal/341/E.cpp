#include<bits/stdc++.h>
using namespace std;
int a[1005];
vector<pair<int,int> > ans;
void opera(int x,int y){
	ans.push_back(make_pair(x,y));
	if(a[x]>a[y]) swap(x,y);
	a[y]-=a[x]; a[x]<<=1;
}
void mod(int x,int y,int z){
	int t=a[y]/a[x];	
	for(int i=0;1<<i<=t;++i){
		if((t>>i)&1)
			opera(x,y);
		else 
			opera(x,z);
	}
}
void solve(int x,int y,int z){
	while(1){
		if(a[x]>a[y]) swap(x,y);
		if(a[x]>a[z]) swap(x,z);
		if(a[y]>a[z]) swap(y,z);
		if(a[x]==0) return;
//		printf("[%d %d %d]",a[x],a[y],a[z]);
		mod(x,y,z);
// 		printf("{%d %d %d}\n",a[x],a[y],a[z]);
	}
}
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	while(1){
		vector<int> f;
		for(int i=1;i<=n;++i)
			if(a[i]>0) f.push_back(i);
		if(f.size()<=2) break;
		solve(f[0],f[1],f[2]);
	}
	vector<int> f;
	for(int i=1;i<=n;++i)
		if(a[i]>0) f.push_back(i);
	if(f.size()!=2) puts("-1");
	else{
		printf("%d\n",(int)ans.size());
		for(auto x:ans) printf("%d %d\n",x.first,x.second);
	}
	return 0;
}