#include<bits/stdc++.h>

using namespace std;

const int maxn=200006;

struct plc{
	int v,i;
};
int n,m,k;
int a[maxn];
plc p[maxn];
bool ok[maxn];
int stk[maxn],sth;
bool cmp(plc a,plc b){
	return a.v>b.v;
}

bool cm(int a,int b){
	return a>b;
}
long long calc(int l,int r){
	sth=0;
	for(int i=l;i<=r;i++){
		stk[++sth]=a[i];
	}
	sort(stk+1,stk+1+sth,cm);
	long long ans=0;
	for(int i=1;i<=m;i++){
		ans+=stk[i];
	}
	return ans;
}
int prt[maxn];
int prs;
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		p[i].v=a[i];
		p[i].i=i;
	}
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=m*k;i++){
		ok[p[i].i]=1;
	}
	long long ans=0;
	int cur=0;
	prt[0]=0;
	for(int i=1;i<=n;i++){
		cur+=ok[i];
		if(cur>=m){
			prt[++prs]=i;
			if(prs==k) ans+=calc(prt[prs-1]+1,n);
			else ans+=calc(prt[prs-1]+1,prt[prs]);
			cur=0;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<k;i++) cout<<prt[i]<<' ';
	return 0;
}