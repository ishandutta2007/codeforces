#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define inf 1000000000000000000
#define int long long
using namespace std;
int n,a[500005],p[500005],m,b[500005],pos[500005],sum[500005],f[500005];
vector <int>c[500005];
int tree[500005];
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
inline bool check(){
	int now=1;
	for (int i=1;i<=n;i++){
		if (a[i]==b[now])now++;
		if (now>m)return 1;
	}
	return 0;
}
struct node{
	int num,val,pos;
}num[500005];
inline bool cmp(node a,node b){
	return a.num<b.num;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%lld",&p[i]);
	cin>>m;
	for (int i=1;i<=m;i++)
		scanf("%lld",&b[i]);
	++n,++m;
	a[n]=b[m]=n;
	if (!check()){
		puts("NO");
		return 0;
	}
	puts("YES");
	for (int i=1;i<=m;i++)pos[b[i]]=i;
	for (int i=1;i<=n;i++)
		num[i].num=a[i],num[i].val=max(p[i],0ll),num[i].pos=i;
	for (int i=1;i<=n;i++)
		if (p[i]<0)sum[i]=sum[i-1]-p[i];
		else sum[i]=sum[i-1];
	sort(num+1,num+1+n,cmp);
	for (int i=1;i<=n;i++)
		if (pos[a[i]]!=0)c[pos[a[i]]].push_back(i);
	c[0].push_back(0);
	for (int i=1;i<=n;i++)add(num[i].pos,num[i].val);
	int nowdel=1;
	for (int i=1;i<=m;i++){
		while(nowdel<=n&&num[nowdel].num<=b[i-1])add(num[nowdel].pos,-num[nowdel].val),nowdel++;
		int mn=inf,r=0,tot=c[i-1].size();
		for (int j=0,len=c[i].size();j<len;j++){
			while(r<tot&&c[i-1][r]<c[i][j])mn=min(mn,f[c[i-1][r]]-ask(c[i-1][r])+sum[c[i-1][r]]),r++;
			f[c[i][j]]=mn+ask(c[i][j]-1)-sum[c[i][j]-1];
		}
	}
	cout<<f[c[m][0]]<<endl;
	return 0;
}