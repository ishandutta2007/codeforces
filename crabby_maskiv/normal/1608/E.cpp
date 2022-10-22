#include<bits/stdc++.h>
#define fr first
#define sc second
#define lbt(x) (x&(-x))
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+5;
int n,n1,n2,n3;
int x[N],y[N],c[N],co[N];
ll t[N];
int d1[N],d2[N];
inline int qry(int s){
	int c1=0,c2=0,res=0,i,pos=0;
	for(i=(1<<16);i;i>>=1){
		if(pos+i>n) continue;
		if(c1+d1[pos+i]<=s-c2-d2[pos+i]){
			pos+=i;
			c1+=d1[pos];
			c2+=d2[pos];
		}
	}
	res=min(c1,s-c2);
	if(pos<n){
		c1=0;c2=0;
		for(i=pos+1;i;i-=lbt(i)){
			c1+=d1[i];
			c2+=d2[i];
		}
		res=max(res,min(c1,s-c2));
	}
	return res;
}
pii a1[N],a2[N],a3[N];
inline int solve1(){
	//cerr<<"1"<<endl;
	int i,j;
	n1=n2=n3=0;
	for(i=1;i<=n;i++){
		if(c[i]==1) a1[++n1]={x[i],y[i]};
		if(c[i]==2) a2[++n2]={x[i],y[i]};
		if(c[i]==3) a3[++n3]={x[i],y[i]};
	}
	sort(a1+1,a1+n1+1);
	sort(a2+1,a2+n2+1);
	sort(a3+1,a3+n3+1);
	for(i=1;i<=n;i++) d1[i]=d2[i]=0;
	int p1=1,p2=1,res=0;
	for(i=1;i<=n3;i++){
		while(p1<=n1&&a1[p1].fr<a3[i].fr){
			for(j=a1[p1].sc;j<=n;j+=lbt(j)) d1[j]++;
			p1++;
		}
		while(p2<=n2&&a2[p2].fr<a3[i].fr){
			for(j=a2[p2].sc;j<=n;j+=lbt(j)) d2[j]++;
			p2++;
		}
		res=max(res,min(n3-i+1,qry(p2-1)));
	}
	return res;
}
int b1[N],b2[N],b3[N];
inline int solve2(){
	//cerr<<"2"<<endl;
	int i,j;
	n1=n2=n3=0;
	for(i=1;i<=n;i++){
		if(c[i]==1) b1[++n1]=x[i];
		if(c[i]==2) b2[++n2]=x[i];
		if(c[i]==3) b3[++n3]=x[i];
	}
	sort(b1+1,b1+n1+1);
	sort(b2+1,b2+n2+1);
	sort(b3+1,b3+n3+1);
	for(i=1;i<=n;i++) d1[i]=d2[i]=0;
	int p1=1,p2=1,res=0;
	for(i=1;i<=n3;i++){
		while(p1<=n1&&b1[p1]<b3[i]){
			for(j=b1[p1];j<=n;j+=lbt(j)) d1[j]++;
			p1++;
		}
		while(p2<=n2&&b2[p2]<b3[i]){
			for(j=b2[p2];j<=n;j+=lbt(j)) d2[j]++;
			p2++;
		}
		res=max(res,min(n3-i+1,qry(p2-1)));
	}
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>x[i]>>y[i]>>co[i];
	for(i=1;i<=n;i++) t[i]=x[i];
	sort(t+1,t+n+1);
	for(i=1;i<=n;i++) x[i]=lower_bound(t+1,t+n+1,x[i])-t;
	for(i=1;i<=n;i++) t[i]=y[i];
	sort(t+1,t+n+1);
	for(i=1;i<=n;i++) y[i]=lower_bound(t+1,t+n+1,y[i])-t;
	int ans=0;
	for(j=1;j<=4;j++){
		int f[4]={0,1,2,3};
		do{
			for(i=1;i<=n;i++) c[i]=f[co[i]];
			ans=max(ans,solve1());
			ans=max(ans,solve2());
		}while(next_permutation(f+1,f+4));
		for(i=1;i<=n;i++){
			swap(x[i],y[i]);
			y[i]=n-y[i]+1;
		}
	}
	cout<<ans*3;
	return 0;
}