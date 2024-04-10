#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <cmath>
#define base 1000003
#define ull unsigned long long
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct node{
	int c[10],w;
	bool operator <(const node &x)const{
		return w<x.w;
	}
}a[100005],sta[100005];
int n,m,tot;
unordered_map<ull,int> c;
int cnt[100005];
ull base_pow[500005];
int lowbit(int x){
	return x&(-x);
}
void del(node awa){
	for (int i=1;i<(1<<m);i++){
		ull s=0;
		for (int j=0;j<m;j++)
			if (i&(1<<j))s=s+base_pow[awa.c[j]];
		c[s]--;
	}
	return;
}
void ins(node awa){
	for (int i=1;i<(1<<m);i++){
		ull s=0;
		for (int j=0;j<m;j++)
			if (i&(1<<j))s=s+base_pow[awa.c[j]];
		c[s]++;
	}
	return;
}
int ask(node awa){
	int ans=0;
	for (int i=1;i<(1<<m);i++){
		ull s=0;
		for (int j=0;j<m;j++)
			if (i&(1<<j))s=s+base_pow[awa.c[j]];
		if ((cnt[i]-1)&1)ans-=c[s];
		else ans+=c[s];
	}
	return ans;
}
int _a[500005],len;
int lower(int x){
	int l=1,r=len,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (_a[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
signed main(){
	for (int i=1;i<=100000;i++)cnt[i]=cnt[i-lowbit(i)]+1;
	base_pow[0]=1;
	for (int i=1;i<=500000;i++)base_pow[i]=base_pow[i-1]*base;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		for (int j=0;j<m;j++)
			a[i].c[j]=read(),_a[++len]=a[i].c[j];
		a[i].w=read();
	}
	sort(_a+1,_a+1+len);
	for (int i=1;i<=n;i++)
		for (int j=0;j<m;j++)a[i].c[j]=lower(a[i].c[j]);
	sort(a+1,a+1+n);
	int ans=2000000001;
	for (int i=1;i<=n;i++){
		node qwq;
		qwq.w=-1;
		while(tot>0&&ask(a[i])<tot){
			qwq=sta[tot];
			del(sta[tot]);
			tot--;
		}
		if (qwq.w!=-1)ans=min(ans,a[i].w+qwq.w);
		ins(a[i]);
		sta[++tot]=a[i];
	}
	if (ans==2000000001)ans=-1;
	cout<<ans<<endl;
	return 0;
}