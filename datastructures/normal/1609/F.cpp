#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
ll read(){
	ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct BIT{
	int tree[1000005],maxn;
	void mem(){
		memset(tree,0,sizeof(tree));
		maxn=1000000;
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
};
struct DataStructures{
	BIT bit1,bit2;
	int maxn;
	void mem(){
		bit1.mem();
		bit2.mem();
		maxn=1000000;
		return;
	}
	void add(int l,int r,int val){
		bit1.add(r,val*r);
		bit2.add(maxn-r+1,val);
		if (l>1){
			bit1.add(l-1,-val*(l-1));
			bit2.add(maxn-(l-1)+1,-val);
		}
		return;
	}
	int ask(int l,int r){
		int ans=0;
		ans+=bit1.ask(r-1)+r*bit2.ask(maxn-r+1);
		if (l>1)ans-=bit1.ask((l-1)-1)+(l-1)*bit2.ask(maxn-(l-1)+1);
		return ans;
	}
}ds1[10],ds2[10];
int n,cnt[1000005];
ll a[1000005],ans;
int now;
int q1[1000005],t1,q2[1000005],t2;
int book[60];
int qwq;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++){
		for (int j=0;j<60;j++)
			if (a[i]&(1ll<<j))cnt[i]++;
		book[cnt[i]]=1;
	}
	for (int w=0;w<6;w++){
		for (int i=0;i<10;i++)ds1[i].mem(),ds2[i].mem();
		t1=t2=0;
		now=0;
		for (int i=1;i<=n;i++){
			while(t1>0&&a[q1[t1]]>a[i]){
				qwq=cnt[q1[t1]];
				if (qwq>=w*10&&qwq<(w+1)*10)now-=ds2[qwq%10].ask(q1[t1-1]+1,q1[t1]),ds1[qwq%10].add(q1[t1-1]+1,q1[t1],-1);
				--t1;
			}
			qwq=cnt[i];
			if (qwq>=w*10&&qwq<(w+1)*10)now+=ds2[qwq%10].ask(q1[t1]+1,i),ds1[qwq%10].add(q1[t1]+1,i,1);
			q1[++t1]=i;
			while(t2>0&&a[q2[t2]]<a[i]){
				qwq=cnt[q2[t2]];
				if (qwq>=w*10&&qwq<(w+1)*10)now-=ds1[qwq%10].ask(q2[t2-1]+1,q2[t2]),ds2[qwq%10].add(q2[t2-1]+1,q2[t2],-1);
				--t2;
			}
			qwq=cnt[i];
			if (qwq>=w*10&&qwq<(w+1)*10)now+=ds1[qwq%10].ask(q2[t2]+1,i),ds2[qwq%10].add(q2[t2]+1,i,1);
			q2[++t2]=i;
			ans+=now;
		}
	}
	cout<<ans<<endl;
	return 0;
}