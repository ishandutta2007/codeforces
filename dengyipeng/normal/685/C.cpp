#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 100005
#define ll long long
using namespace std;

int T,n,i,j,k;
ll x[maxn],y[maxn],z[maxn];

ll Abs(ll x){return max(x,-x);}
ll up(ll x){return (x>0)?(x+1)/2:x/2;}
ll down(ll x){return (x>0)?x/2:(x-1)/2;}

ll l1,r1,l2,r2,l3,r3,l4,r4;
ll L1,L2,L3,L4,R1,R2,R3,R4;
ll A,B,C,X,Y,Z;

int check(ll d){
	l1=l2=l3=l4=-9e18,r1=r2=r3=r4=9e18;
	for(i=1;i<=n;i++){
		r1=min(r1,d+x[i]+y[i]+z[i]);
		r2=min(r2,d+x[i]+y[i]-z[i]);
		r3=min(r3,d+x[i]-y[i]+z[i]);
		r4=min(r4,d+x[i]-y[i]-z[i]);
		l1=max(l1,x[i]+y[i]+z[i]-d);
		l2=max(l2,x[i]+y[i]-z[i]-d);
		l3=max(l3,x[i]-y[i]+z[i]-d);
		l4=max(l4,x[i]-y[i]-z[i]-d);
	}
	swap(l4,r4),l4=-l4,r4=-r4;
	for(int t=0;t<2;t++){
		L1=up(l1-3*t),R1=down(r1-3*t);
		L2=up(l2-t),R2=down(r2-t);
		L3=up(l3-t),R3=down(r3-t);
		L4=up(l4-t),R4=down(r4-t);
		if (L1<=R1&&L2<=R2&&L3<=R3&&L4<=R4)
		if (max(L2+L3+L4,L1)<=min(R2+R3+R4,R1)){
			ll l=L2+L3+L4,r=R2+R3+L4;
			if (max(L1,l)<=min(R1,r)) C=L4; 
			else C=L4+L1-r;
			l=L2+L3+C,r=R2+L3+C;
			if (max(L1,l)<=min(R1,r)) B=L3;
			else B=L3+L1-r;
			l=L2+B+C,r=L2+B+C;
			if (max(L1,l)<=min(R1,r)) A=L2;
			else A=L2+L1-r;
//			if (A+B+C<L1||A+B+C>R1|| A<L2||A>R2|| B<L3||B>R3|| C<L4||C>R4)
//				printf("!");
			A=A*2+t,B=B*2+t,C=C*2+t;
//			if (A+B+C<l1||A+B+C>r1|| A<l2||A>r2|| B<l3||B>r3|| C<l4||C>r4)
//				printf("!");
			X=(A+B)/2,Y=(A+C)/2,Z=(B+C)/2;
//			for(int i=1;i<=n;i++)
//				if (Abs(X-x[i])+Abs(Y-y[i])+Abs(Z-z[i])>d) 	
//					printf("!");
			return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n); 
		for(i=1;i<=n;i++) scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
		ll l=0,r=0,mid;
		for(i=1;i<=n;i++) r=max(r,Abs(x[i])+Abs(y[i])+Abs(z[i])); r=r*2;
//		check(0);
//		ll ans=0;
		while (l<=r){
			mid=(l+r)>>1;
			if (check(mid)) r=mid-1;
			else l=mid+1;
		}
//		printf("%lld\n",ans);
		printf("%lld %lld %lld\n",X,Y,Z);
	}
}