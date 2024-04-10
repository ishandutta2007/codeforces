#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define inf 1000000000
using namespace std;
int n,m,a[1000005],_a[1000005],b[1000005],f[1000005];
struct BIT{
	int tree[1000005],maxn;
	BIT(){
		maxn=1000000;
		for (int i=0;i<=maxn;i++)tree[i]=inf;
		return;
	}
	inline int lowbit(register int x){
		return x&(-x);
	}
	inline void add(register int pos,register int val){
		while(pos<=maxn)tree[pos]=min(tree[pos],val),pos+=lowbit(pos);
		return;
	}
	inline void clear(register int pos){
		while(pos<=maxn)tree[pos]=inf,pos+=lowbit(pos);
		return;
	}
	inline int ask(register int pos){
		register int ans=inf;
		while(pos)ans=min(ans,tree[pos]),pos-=lowbit(pos);
		return ans;
	}
}bit;
inline int lower(int x){
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (_a[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]-=i,_a[i]=a[i];
	a[++n]=inf;
	_a[n]=a[n];
	for (int i=1;i<=m;i++)scanf("%d",&b[i]);
	sort(_a+1,_a+1+n);
	for (int i=1;i<=n;i++)a[i]=lower(a[i]);
	int now=1;
	for (int i=1;i<=n;i++){
		f[i]=bit.ask(a[i])+i-1;
		if (i<=b[1]||b[1]==0)f[i]=min(f[i],i-1);
		if (b[now]==i){
			for (int j=b[now-1];j<=b[now];j++)
				if (j>0)bit.clear(a[j]);
			now++;
		}
		bit.add(a[i],f[i]-i);
	}
	if (f[n]>n)cout<<-1<<endl;
	else cout<<f[n]<<endl;
	return 0; 
}
//f[i][j]=min(f[j]+i-j-1)=min(f[j]-j)+i-1   (a[i]-a[j]>=i-j  ->  a[i]-i>=a[j]-j)