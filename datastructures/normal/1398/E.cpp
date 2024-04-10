#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
struct BIT{
	int tree[1000005];
	int maxn;
	BIT(){
		maxn=1000000;
		memset(tree,0,sizeof(tree));
		return;
	}
	inline int lowbit(int x){
		return x&(-x);
	} 
	inline void add(int pos,int val){
		while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
		return;
	}
	inline int ask(int pos){
		int ans=0;
		while(pos)ans+=tree[pos],pos-=lowbit(pos);
		return ans;
	}
	inline int kth(int x){
		if (x==0)return 0; 
		int l=1,r=maxn,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			if (ask(mid)>=x)ans=mid,r=mid-1;
			else l=mid+1;
		}
		return ans;
	}
}bit1,bit2,bit3,bit4,bit5,bit6;
inline bool cmp(int a,int b){
	return a>b;
}
int n,opt[200005],val[200005],s[200005],tot,num0,num1,sum;
inline int lower(int x){
	int l=1,r=tot,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (s[mid]<=x)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%lld%lld",&opt[i],&val[i]);
		if (val[i]>0)s[++tot]=val[i];
	}
	sort(s+1,s+1+tot,cmp);
	for (int i=1;i<=n;i++)
		if (val[i]>0)val[i]=lower(val[i]);
		else val[i]=-lower(-val[i]);
	for (int i=1;i<=n;i++){
		if (val[i]<0){
			if (opt[i]==1)bit1.add(-val[i],-1),bit2.add(-val[i],-s[-val[i]]),num0--;
			else bit3.add(-val[i],-1),bit4.add(-val[i],-s[-val[i]]),num1--;
			bit5.add(-val[i],-1),bit6.add(-val[i],-s[-val[i]]);
			sum-=s[-val[i]];
		}
		else{
			if (opt[i]==1)bit1.add(val[i],1),bit2.add(val[i],s[val[i]]),num0++;
			else bit3.add(val[i],1),bit4.add(val[i],s[val[i]]),num1++;
			bit5.add(val[i],1),bit6.add(val[i],s[val[i]]);
			sum+=s[val[i]];
		}
		if (num0==0){
			printf("%lld\n",sum);
			continue;
		}
		int pos=bit5.kth(num0);
		if (bit1.ask(pos)==num0)
			printf("%lld\n",sum+bit2.ask(bit1.kth(num0-1))+bit4.ask(bit3.kth(1)));
		else printf("%lld\n",sum+bit6.ask(pos));
	}
}