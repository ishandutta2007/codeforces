#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#define int long long
using namespace std;
int ask(int i,int j){
	cout<<'?'<<' '<<i<<' '<<j<<endl;
	fflush(stdout);
	int ans;
	cin>>ans;
	return ans;
}
int rnd(int w){
	int x=rand()*rand()+rand();
	x=(x%w+w)%w;
	x++;
	return x;
}
int gcd(int a,int b){
	if (b==0)return a;
	return gcd(b,a%b);
}
int lcm(int a,int b){
	return a*b/gcd(a,b);
}
int t,n,tot,ans[200005];
struct node{
	int x,y,val;
}c[200005];
bool cmp(node a,node b){
	return a.val<b.val;
}
int qwq_maxval[200005],real_maxval[200005],book[200005];
int p[200005],totp;
bool check(int pos,int l,int r){
	int len=r-l+1;
	for (int i=1;i<=len;i++)real_maxval[i]=lcm(i+l-1,r);
	sort(real_maxval+1,real_maxval+1+len);
	int awa=0;
	for (int i=1;i<=tot;i++)
		if (c[i].x==pos||c[i].y==pos)qwq_maxval[++awa]=c[i].val;
	qwq_maxval[++awa]=r;
	sort(qwq_maxval+1,qwq_maxval+1+len);
	for (int i=1;i<=len;i++)
		if (real_maxval[i]!=qwq_maxval[i])return 0;
	return 1;
}
int calc(int x){
	int ans=0;
	for (int i=1;p[i]*p[i]<=x;i++)
		if (x%p[i]==0){
			ans=max(ans,p[i]);
			while(x%p[i]==0)x/=p[i];
		}
	ans=max(ans,x);
	return ans;
}
signed main(){
	srand(time(NULL));
	ios::sync_with_stdio(false);
	for (int i=2;i<=200000;i++){
		int fg=1;
		for (int j=2;j*j<=i;j++)
			if (i%j==0)fg=0;
		if (fg==1)p[++totp]=i;
	}
	cin>>t;
	while(t--){
		cin>>n;
		if (n<=100){
			tot=0;
			for (int i=1;i<=n;i++)
				for (int j=1;j<i;j++){
					++tot;
					c[tot].x=i,c[tot].y=j,c[tot].val=ask(i,j);
				}
			memset(ans,0,sizeof(ans));
			for (int i=1;i<=n-2;i++){
				sort(c+1,c+1+tot,cmp);
				int val=0,pos=0;
				for (int j=1;j*j<=c[tot].val;j++)
					if (c[tot].val%j==0&&j+1==c[tot].val/j){
						val=j+1;
						continue;
					}
				if (check(c[tot].x,val-n+i,val)){
					ans[c[tot].x]=val;
					ans[c[tot].y]=val-1;
					pos=c[tot].x;
				}
				else{
					ans[c[tot].y]=val;
					ans[c[tot].x]=val-1;
					pos=c[tot].y;
				}
				int _tot=tot;
				tot=0;
				for (int j=1;j<=_tot;j++){
					if (c[j].x!=pos&&c[j].y!=pos){
						++tot;
						c[tot].x=c[j].x,c[tot].y=c[j].y,c[tot].val=c[j].val;
					}
				}
			}
			memset(book,0,sizeof(book));
			int mx=0;
			for (int i=1;i<=n;i++)book[ans[i]]=1,mx=max(mx,ans[i]);
			int qwqval=0;
			for (int i=mx-n+1;i<=mx;i++)
				if (book[i]==0)qwqval=i;
			for (int i=1;i<=n;i++)
				if (ans[i]==0)ans[i]=qwqval;
			cout<<"! ";
			for (int i=1;i<=n;i++)cout<<ans[i]<<' ';
			cout<<endl;
			fflush(stdout);
		}
		else{
			int mx=0,idx=0,idy=0;
			for (int i=1;i<=3000;i++){
				int x=rnd(n),y=rnd(n);
				while(x==y)x=rnd(n),y=rnd(n);
				int val=ask(x,y);
				if (calc(val)>mx)mx=calc(val),idx=x,idy=y;
			}
			int fg=1,pos=0;
			for (int i=1;i<=1000;i++){
				int x=rnd(n);
				while(x==idx||x==idy)x=rnd(n);
				if (calc(ask(idx,x))<calc(ask(idy,x)))fg=0;
			}
			if (fg==1)pos=idx;
			else pos=idy;
			ans[pos]=mx;
			for (int i=1;i<=n;i++)
				if (i!=pos)ans[i]=ask(pos,i)/mx;	
			cout<<"! ";
			for (int i=1;i<=n;i++)cout<<ans[i]<<' ';
			fflush(stdout);
		}
	}
	return 0;
}