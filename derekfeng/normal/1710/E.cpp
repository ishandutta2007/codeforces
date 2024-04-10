#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,sx,sy,md;
int a[200004],b[200004];
ll ds[200004];int vl[200004];
int ps[200004];
ll sum(int x,int y,bool s){
	ll res=0;int pos=ps[y];
	if(x>=1&&y>=1){
		int ppos=min(pos,x);
		res+=(ll)ppos*y+(ds[x]-ds[ppos]);
	}
	if(x<n&&y<m){
		if(x<pos)res+=(ll)m*(pos-x)-(ds[pos]-ds[x]);
		pos=max(pos,x);
		res+=(ll)(n-pos)*(m-y);
	}
	if(s){
		if(sx<=x&&sy<=y&&a[sx]+b[sy]<=md)res--;
		if(sx>x&&sy>y&&a[sx]+b[sy]>md)res--;
	}
	return res;
}
bool check(){
	if(a[sx]+b[sy]<=md)return 1;
	vl[0]=m;
	for(int i=1;i<=n;i++){
		vl[i]=vl[i-1];
		for(;vl[i]&&a[i]+b[vl[i]]>md;vl[i]--);
		ds[i]=ds[i-1]+vl[i];
	}
	ps[0]=n;
	for(int i=1;i<=m;i++){
		ps[i]=ps[i-1];
		while(ps[i]&&vl[ps[i]]<i)ps[i]--;
	}
	ll ans0=0,ans1=0;
	for(int i=0,it=0;i<=n;i++){
		while(it<m&&sum(i,it,0)<=sum(i,it+1,0))it++;
		ans0=max(ans0,sum(i,it,0));
	}
	for(int i=0,it=0;i<=n;i++){
		while(it<m&&sum(i,it,1)<=sum(i,it+1,1))it++;
		ans1=max(ans1,sum(i,it,1));
	}
	return ans0!=ans1+1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	sx=a[1],sy=b[1];
	sort(a+1,a+n+1),sort(b+1,b+m+1);
	sx=lower_bound(a+1,a+n+1,sx)-a;
	sy=lower_bound(b+1,b+m+1,sy)-b;
	int ld=0,rd=1e9+1;
	while(rd>ld+1){
		md=(ld+rd)>>1;
		if(check())rd=md;
		else ld=md;
	}
	printf("%d",rd);
}