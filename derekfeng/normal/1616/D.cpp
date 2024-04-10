#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,a[50004],x;
ll d[50004];
vector<ll>all;
int bit[50004],m;
void upd(int i,int x){
	for(;i;i-=i&-i)bit[i]=max(bit[i],x);
}
int qry(int i){
	int res=-1;
	for(;i<=m;i+=i&-i)res=max(res,bit[i]);
	return res;
}
void sol(){
	all.clear();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&x);
	all.push_back(0),all.push_back(-1e18);
	for(int i=1;i<=n;i++)a[i]-=x,d[i]=d[i-1]+a[i],all.push_back(d[i]);
	sort(all.begin(),all.end()),all.erase(unique(all.begin(),all.end()),all.end());
	m=all.size()-1;
	for(int i=0;i<=n;i++)d[i]=lower_bound(all.begin(),all.end(),d[i])-all.begin();
	for(int i=1;i<=m;i++)bit[i]=-1;
	int lst=0,ans=0;
	for(int i=1;i<=n;i++){
		if(i>1)upd(d[i-2]-1,i-2);
		int p=qry(d[i]);
		if(p<0)continue;
		int L=p+1,R=i;
		if(L<=lst&lst<=R)continue;
		lst=R,ans++;
	}
	printf("%d\n",n-ans);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}