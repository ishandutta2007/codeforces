#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
#define rank rk124232
#define y1 y20160116
#define y0 y20160110
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
namespace Mymath{
	LL qp(LL x,LL p,LL mod){
		LL ans=1;
		while (p){
			if (p&1) ans=ans*x%mod;
			x=x*x%mod;
			p>>=1;
		}
		return ans;
	}
	LL inv(LL x,LL mod){
		return qp(x,mod-2,mod);
	}
	LL C(LL N,LL K,LL fact[],LL mod){
		return fact[N]*inv(fact[K],mod)%mod*inv(fact[N-K],mod)%mod;
	}
	template <typename Tp> Tp gcd(Tp A,Tp B){
		if (B==0) return A;
		return gcd(B,A%B);
	}
	template <typename Tp> Tp lcm(Tp A,Tp B){
		return A*B/gcd(A,B);
	}
};
namespace fwt{
	using namespace Mymath;
	void FWT(int a[],int n,LL mod)
	{
	    for(int d=1;d<n;d<<=1)
	        for(int m=d<<1,i=0;i<n;i+=m)
	            for(int j=0;j<d;j++)
	            {
	                int x=a[i+j],y=a[i+j+d];
	                a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod;
	                //xor:a[i+j]=x+y,a[i+j+d]=x-y;
	                //and:a[i+j]=x+y;
	                //or:a[i+j+d]=x+y;
	            }
	}

	void UFWT(int a[],int n,LL mod)
	{
		LL rev=inv(2,mod);
	    for(int d=1;d<n;d<<=1)
	        for(int m=d<<1,i=0;i<n;i+=m)
	            for(int j=0;j<d;j++)
	            {
	                int x=a[i+j],y=a[i+j+d];
	                a[i+j]=1LL*(x+y)*rev%mod,a[i+j+d]=(1LL*(x-y)*rev%mod+mod)%mod;
	                //xor:a[i+j]=(x+y)/2,a[i+j+d]=(x-y)/2;
	                //and:a[i+j]=x-y;
	                //or:a[i+j+d]=y-x;
	            }
	}
	void solve(int a[],int b[],int n,LL mod)
	{
	    FWT(a,n,mod);
	    FWT(b,n,mod);
	    for(int i=0;i<n;i++) a[i]=1LL*a[i]*b[i]%mod;
	    UFWT(a,n,mod);
	}
};
const int Maxn=1e6+5;
int n;
char c[Maxn];
int ppos[Maxn],kp;
int apos[Maxn],ka;
int dir[Maxn];// 1:right -1:left 2: right(const) -2:left(have ancestor)
int fc[Maxn];
int fc2[Maxn];
bool check(int l){
	ka=kp=0;
	for (int i=0;i<n;i++){
		if (c[i]=='P'){
			ppos[kp++]=i;
		}
	}
	for (int i=0;i<n;i++){
		if (c[i]=='*'){
			apos[ka++]=i;
		}
	} 
	int nowgt=0;
	for (int i=0;i<kp;i++){
		//cout<<i<<' '<<nowgt<<endl;
		if (ppos[i]<apos[nowgt]){
			dir[i]=2;
			while (nowgt<ka && ppos[i]+l>=apos[nowgt]) nowgt++;
			if (nowgt==ka) return true;
		}
		else{
			if (ppos[i]-l>apos[nowgt]) return false;
			if (i==0){
				dir[i]=-1;
				fc[i]=nowgt;
				while (nowgt<ka && ppos[i]>=apos[nowgt]) nowgt++;
				if (nowgt==ka) return true;
				continue;
			}
			if (dir[i-1]==-1){
				int xp=apos[fc[i-1]];
				if (ppos[i]-l<=xp){
					dir[i-1]=1;
					dir[i]=-2;
					fc2[i]=nowgt;
					while (nowgt<ka && ppos[i-1]+l>=apos[nowgt]) nowgt++;
					if (nowgt==ka) return true;
					fc[i]=fc[i-1];
				}
				else{
					fc[i]=nowgt;
					dir[i]=-1;
					while (nowgt<ka && ppos[i]>=apos[nowgt]) nowgt++;
					if (nowgt==ka) return true;
				}
			}
			else if (dir[i-1]==-2){
				int xp=apos[fc[i-1]];
				if (ppos[i]-l<=xp){
					dir[i-1]=1;
					dir[i]=-2;
					fc2[i]=nowgt;
					while (nowgt<ka && ppos[i-1]+l>=apos[nowgt]) nowgt++;
					if (nowgt==ka) return true;
					fc[i]=fc[i-1];
				}
				else{
					xp=apos[fc2[i-1]];
					if (ppos[i]-l<=xp){
						dir[i-2]=-1;
						dir[i-1]=1;
						dir[i]=-2;
						fc2[i]=nowgt;
						fc[i]=fc[i-1];
						while (nowgt<ka && ppos[i-1]+l>=apos[nowgt]) nowgt++;
						if (nowgt==ka) return true;
					}
					else{
						fc[i]=nowgt;
						dir[i]=-1;
						while (nowgt<ka && ppos[i]>=apos[nowgt]) nowgt++;
						if (nowgt==ka) return true;
					}
				}
			}
			else{
				fc[i]=nowgt;
				dir[i]=-1;
				while (nowgt<ka && ppos[i]>=apos[nowgt]) nowgt++;
				if (nowgt==ka) return true;
			}
		}
	}
	return false;
}
int main(){
	scanf("%d",&n);
	scanf("%s",c);
	int cnt=0;
	int pos;
	int ca=0;
	for (int i=0;i<n;i++){
		if (c[i]=='P') cnt++,pos=i;
		if (c[i]=='*') ca++;
	}
	if (cnt==1){
		int c1=0,c2=0;
		int l=n,r=-1;
		for (int i=0;i<pos;i++){
			if (c[i]=='*') c1++,l=min(l,i);
		}
		for (int i=pos+1;i<n;i++){
			if (c[i]=='*') c2++,r=max(r,i);
		}
		if(c1>c2){
			printf("%d %d\n",c1,pos-l);
		}
		else if (c2>c1){
			printf("%d %d\n",c2,r-pos);
		}
		else{
			printf("%d %d\n",c1,min(pos-l,r-pos));
		}
		return 0;
	}
	//cerr<<123<<endl;
	printf("%d ",ca);
	int lo=0,hi=n;
	while (hi-lo>1){
		int mid=lo+hi>>1;
		if (check(mid)){
			hi=mid;
		}
		else{
			lo=mid;
		}
	}
	printf("%d\n",hi);
}
/*
6
*.P*P*
*/