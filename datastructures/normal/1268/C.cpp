#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std; 
int n,p[200005],pos[200005];
struct BIT{
	int tree[200005];
	BIT(){
		memset(tree,0,sizeof(tree));
		return;
	}
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void add(int pos,int val){
		while(pos<=n)tree[pos]+=val,pos+=lowbit(pos);
		return;
	}
	inline int ask(int pos){
		int ans=0;
		while(pos)ans+=tree[pos],pos-=lowbit(pos);
		return ans;
	}
}bit1,bit2;
int now;
inline int calc(int pos){
	int num1=bit1.ask(pos-1),num2=bit1.ask(n)-bit1.ask(pos);
	int dis1=pos*num1-bit2.ask(pos-1),dis2=(bit2.ask(n)-bit2.ask(pos))-pos*num2;
	return (dis1-num1*(num1+1)/2)+(dis2-num2*(num2+1)/2);
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld",&p[i]),pos[p[i]]=i;
	for (int i=1;i<=n;i++){
		bit1.add(pos[i],1);
		bit2.add(pos[i],pos[i]);
		now+=bit1.ask(n)-bit1.ask(pos[i]);
		int l=1,r=n,pos=0;
		while(l<=r){
			int mid=(l+r)/2;
			if (bit1.ask(mid)>=(i+1)/2)pos=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%lld ",now+calc(pos));
	}
	return 0;
}