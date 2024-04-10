#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mod 1000000007
using namespace std;
void upd(int &x,int y){
	x+=y;
	if (x>=mod)x-=mod;
	return;
}
struct BIT{
	int tree[200005],maxn;
	void mem(){
		memset(tree,0,sizeof(tree));
		maxn=200000;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		while(pos<=maxn)upd(tree[pos],val),pos+=lowbit(pos);
		return;
	}
	int ask(int l,int r){
		if (l>r)return 0;
		int ans=0;
		while(r)upd(ans,tree[r]),r-=lowbit(r);
		l--;
		while(l)upd(ans,mod-tree[l]),l-=lowbit(l);
		return ans;
	}
}bit1,bit2,bit3;
int t,n,a[200005],_a[200005];
int pre[200005],suf[200005],mx[200005],ans;
int lower(int x){
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (_a[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int main(){
	cin>>t;
	while(t--){
		bit1.mem(),bit2.mem(),bit3.mem();
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]),_a[i]=a[i];
		sort(_a+1,_a+1+n);
		for (int i=1;i<=n;i++)a[i]=lower(a[i]);
		for (int i=1;i<=n;i++){
			pre[i]=1;
			upd(pre[i],bit1.ask(1,a[i]-1));
			bit1.add(a[i],pre[i]);
		}
		for (int i=n;i>=1;i--){
			suf[i]=1;
			upd(suf[i],bit2.ask(a[i]+1,n));
			bit2.add(a[i],suf[i]);
		}
		memset(mx,0,sizeof(mx));
		ans=0;
		for (int i=n;i>=1;i--){
			if (a[i]>=mx[i+1]){
				mx[i]=a[i];
				continue;
			}
			mx[i]=mx[i+1];
			int l=i+1,r=n,p=0;
			while(l<=r){
				int mid=(l+r)/2;
				if (mx[mid]>a[i])p=mid,l=mid+1;
				else r=mid-1;
			}
			int qwq=1;
			upd(qwq,bit3.ask(a[i]+1,a[p]-1));
			int awa=suf[i];
			upd(awa,mod-qwq);
			upd(ans,1ll*pre[i]*awa%mod);
			bit3.add(a[i],qwq);
		}
		cout<<ans<<endl;
	}
	return 0;
}