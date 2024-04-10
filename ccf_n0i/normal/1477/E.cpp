#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
struct bit{
	int a[1000005];
	long long s[1000005];
	void ins(int x,int v){
		int i;
		for(i=x;i<=1000001;i+=(i&-i)){
			a[i]+=v;s[i]+=1ll*v*x;
		}
	}
	int kth(int x){
		int s=0,i;
		for(i=20;i>=0;i--){
			if(s+(1<<i)>1000001) continue;
			if(x>a[s+(1<<i)]){
				s+=(1<<i);
				x-=a[s];
			}
		}
		return s+1;
	}
	int query0(int x){
		int ss=0;
		while(x){
			ss+=a[x];
			x-=(x&-x);
		}
		return ss;
	}
	long long query1(int x){
		long long ss=0;
		while(x){
			ss+=s[x];
			x-=(x&-x);
		}
		return ss;
	}
	int query0(int l,int r){
		return query0(r)-query0(l-1);
	}
	long long query1(int l,int r){
		return query1(r)-query1(l-1);
	}
}t1,t2;
int n,m,q,i,j,a[200005],b[200005],ami;
long long calc0(int v,int k){
	int t=v-k;
	int t0=max(1,min(1000001,t));
	long long ans=-(t2.query1(t0,1000001)-1ll*t2.query0(t0,1000001)*t);
	t=min(t,ami);
	ans+=t1.query1(1,1000001)-1ll*n*t;
	return ans;
}
long long calca(int x,int k){
	return calc0(x,k)-max(x-ami,x-x+k)+k;
}
long long calcb(int x,int k){
	return calc0(x,k)-max(0,x-x+k)+k;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,n){
		int x;scanf("%d",&x);x++;
		t1.ins(x,1);a[i]=x;
	}
	rep(i,m){
		int x;scanf("%d",&x);x++;
		t2.ins(x,1);b[i]=x;
	}
	while(q--){
		int op,x;
		scanf("%d%d",&op,&x);
		if(op==1){
			t1.ins(a[x],-1);
			scanf("%d",&a[x]);
			a[x]++;
			t1.ins(a[x],1);
		}
		if(op==2){
			t2.ins(b[x],-1);
			scanf("%d",&b[x]);
			b[x]++;
			t2.ins(b[x],1);
		}
		if(op==3){
			ami=min(t1.kth(1),t2.kth(1));
			long long ans=max(calca(t1.kth(1),x),calca(t1.kth(n),x));
			ans=max(ans,calcb(t2.kth(1),x));
			ans=max(ans,calcb(t2.kth(m),x));
			int t=t2.kth(m)+x;
			t=t1.query0(t);
			if(1<=t&&t<=n){
				ans=max(ans,calca(t1.kth(t),x));
			}
			t++;
			if(1<=t&&t<=n){
				ans=max(ans,calca(t1.kth(t),x));
			}
			
			t=ami+x;
			t=t1.query0(min(1000001,t));
			if(1<=t&&t<=n){
				ans=max(ans,calca(t1.kth(t),x));
			}
			t++;
			if(1<=t&&t<=n){
				ans=max(ans,calca(t1.kth(t),x));
			}
			t=ami+x;
			t=t2.query0(min(1000001,t));
			if(1<=t&&t<=m){
				ans=max(ans,calcb(t2.kth(t),x));
			}
			t++;
			if(1<=t&&t<=m){
				ans=max(ans,calcb(t2.kth(t),x));
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}