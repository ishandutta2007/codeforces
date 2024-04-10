#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct BIT{
	int tree[1000005],maxn;
	void mem(int n){
		maxn=n;
		memset(tree,0,sizeof(int)*(n+5));
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
		return; 
	}
	int ask(int pos){
		int ans=0;
		while(pos)ans+=tree[pos],pos-=lowbit(pos);
		return ans; 
	}
}bit1,bit2;
int t,n,k,a[1000005],_a[1000005],tot;
int book[1000005],qwq[1000005];
void add(int cnt){
	bit1.add(cnt,1);
	bit2.add(cnt,cnt);
	return;
}
int ask(int k){
	int l=1,r=2*n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (bit2.ask(mid)<=k)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return bit1.ask(ans)+(k-bit2.ask(ans))/(ans+1);
}
int lower(int x){
	int l=1,r=tot,ans=0;
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
		cin>>n>>k;
		bit1.mem(3*n);
		bit2.mem(3*n);
		memset(book,0,sizeof(int)*(2*n+5));
		tot=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if (a[i]>n)_a[++tot]=a[i]; 
		}
		sort(_a+1,_a+1+tot);
		for (int i=1;i<=n;i++)
			if (a[i]>n)a[i]=n+lower(a[i]);
		for (int i=1;i<=n;i++)book[a[i]]++;
		qwq[0]=(book[0]==0);
		for (int i=1;i<=2*n;i++)
			qwq[i]=qwq[i-1]+(book[i]==0);
		int ans=1000000000,ovo=0;
		for (int i=2*n;i>0;i--){
			if (book[i]>0)ovo++,add(book[i]);
			if (qwq[i-1]<=k)ans=min(ans,ovo-ask(k));
		}
		if (book[0]>0)ovo++,add(book[0]);
		ans=min(ans,ovo-ask(k));
		cout<<ans<<endl;
	}
	return 0;
}