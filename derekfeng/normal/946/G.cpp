#include<bits/stdc++.h>
using namespace std;
const int inf=2e9;
int n,m,a[200004],f[2][200004];
struct BIT{
	int mn[200004];
	void init(){
		for(int i=1;i<=m;i++)mn[i]=inf;
	}
	void upd(int id,int x){
		for(;id<=m;id+=(id&-id))mn[id]=min(mn[id],x);
	}
	int qry(int id){
		int ret=inf;
		for(;id;id-=(id&-id))ret=min(ret,mn[id]);
		return ret;
	}
}T1,T2;
vector<int>all;
int main(){
	scanf("%d",&n);
	all.push_back(-inf);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[++n]=inf;
	for(int i=1;i<=n;i++)all.push_back(a[i]-i);
	sort(all.begin(),all.end()),all.erase(unique(all.begin(),all.end()),all.end());
	m=all.size()-1;
	for(int i=1;i<=n;i++)f[0][i]=f[1][i]=inf;
	T1.init(),T2.init();
	for(int i=1;i<=n;i++){
		f[0][i]=min(f[0][i],i-1);
		if(i>1)f[1][i]=min(f[1][i],i-2);
		int pos=lower_bound(all.begin(),all.end(),a[i]-i)-all.begin();
		T1.upd(pos,f[0][i]-i),T2.upd(pos,f[1][i]-i);
		if(i+1<=n){
			pos=lower_bound(all.begin(),all.end(),a[i+1]-i-1)-all.begin();
			f[0][i+1]=min(f[0][i+1],T1.qry(pos)+i);
			f[1][i+1]=min(f[1][i+1],T2.qry(pos)+i);
		}
		if(i+2<=n){
			pos=upper_bound(all.begin(),all.end(),a[i+2]-i-1)-all.begin()-1;
			f[1][i+2]=min(f[1][i+2],T1.qry(pos)+i);
		}
	}
	printf("%d\n",min(f[0][n],f[1][n]));
}