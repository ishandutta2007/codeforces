#include<bits/stdc++.h>
typedef long long ll;
const int N=1e5+3;
int n,m,a,mx[N],mn[N],bx[1000001],bn[1000001],t;ll s;
int main(){
	scanf("%d",&n);
	t=n+n-1;
	for(int i=1;i<=n;i++){
	  scanf("%d",&m);
	  mx[i]=0,mn[i]=1000000;
	  for(;m--;){
		scanf("%d",&a);
		if(a>mn[i]){s+=t,t-=2;for(;m--;)scanf("%d",&a);goto Brk;}
		mx[i]=std::max(mx[i],a),mn[i]=std::min(mn[i],a);
	  }
	  bn[mn[i]]++;
	  bx[mx[i]]++;
	  Brk:;
	}
	for(int i=1;i<=1000000;i++)bn[i]+=bn[i-1],s+=(ll)bn[i-1]*bx[i];
	printf("%lld",s);
	return 0;
}