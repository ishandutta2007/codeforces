#include<bits/stdc++.h>
using namespace std;
const int T=256;
int n,q,m,lzy[1003],a[200003],bc[2][6][1003];
void recalc(int B){
	for(int tp=0;tp<2;tp++)
		for(int j=0;j<=m;j++){
			bc[tp][j][B]=j;
			for(int i=B*T+T-1;i>=B*T;i--)
				if(bc[tp][j][B]==0)
					bc[tp][j][B]=(a[i]^tp);
				else
					bc[tp][j][B]=(bc[tp][j][B]+1)%(m+1);
		}
}
int main(){
//	freopen("a.out","w",stdout); 
	cin>>n>>m>>q;
	for(int i=0;i<n;i++){
		long long x;
		scanf("%lld",&x);
		a[i]=x&1;
	}
	for(int i=0;i+T<n;i+=T)
		recalc(i/T);
	while(q--){
		int tp,l,r;
		long long d;
		scanf("%d%d%d",&tp,&l,&r);
		l--;r--;
		if(tp==1){
			scanf("%lld",&d);
			if(!(d&1))continue;
			for(int i=(l/T)*T;i<l;i++)
				a[i]^=1;
			for(int i=(l/T)*T;i+T-1<=r;i+=T)
				lzy[i/T]^=1;
			for(int i=((r+1)/T)*T;i<=r;i++)
				a[i]^=1;
			recalc(l/T);
			recalc(r/T);
		}else{
			int ans=a[r]^lzy[r/T];
			r--;
//			cout<<"!:"<<ans<<' ';
			while(r>=l&&r%T!=T-1){
				if(ans==0)
					ans=a[r]^lzy[r/T];
				else
					ans=(ans+1)%(m+1);
//				cout<<"!:"<<ans<<' ';
				r--;
			}
			while(r-T>=l){
				ans=bc[lzy[r/T]][ans][r/T];
//				cout<<"?:"<<ans<<' ';
				r-=T;
			}
			while(r>=l){
				if(ans==0)
					ans=(a[r]^lzy[r/T]);
				else
					ans=(ans+1)%(m+1);
//				cout<<"w:"<<ans<<' ';
				r--;
			}
			if(ans==1)
				printf("2\n");
			else
				printf("1\n");
		}
	}
}