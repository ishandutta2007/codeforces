#include<bits/stdc++.h>
#define int long long
const int N=20005,mod=998244353,g=3;
using namespace std;

int n,m,k,lim=1;
int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=1ll*x*x%mod)
        if(y&i)
            ans=1ll*ans*x%mod;
    return ans;
}int inv(int k){return gsc(k,mod-2);}
void add(int&x,int y){
	x+=y;while(x>=mod)x-=mod;
}
int jc[N],ij[N],iv[N],r[N];
void init(){
	iv[0]=jc[0]=ij[0]=iv[1]=1;
    for(int i=2;i<N;i++)
        iv[i]=mod-(mod/i)*iv[mod%i]%mod;
    for(int i=1;i<N;i++)
        jc[i]=jc[i-1]*i%mod,ij[i]=ij[i-1]*iv[i]%mod;
	lim=1;while(lim<=k<<1)lim<<=1;
	for(int i=0;i<lim;i++)
		r[i]=(r[i>>1]>>1)|((i&1)*(lim>>1));
}
struct node{
	int a[N];
	node(){memset(a,0,sizeof(a));}
	int&operator[](int b){return a[b];}
	
}res,A;
void ntt(int*a,int ty=1){
	for(int i=0;i<lim;i++)if(r[i]<=i)swap(a[i],a[r[i]]);	
	for(int i=1;i<lim;i<<=1){
		int o=gsc(ty==1?g:inv(g),mod/(i*2)),x,y;
		for(int j=0;j<lim;j+=i<<1)
			for(int k=0,w=1;k<i;k++,w=w*o%mod)
				x=a[j+k],y=a[j+k+i]*w%mod,a[j+k]=(x+y)%mod,a[j+k+i]=(x-y)%mod;
	}
	if(ty==-1){
		int iv=inv(lim);
		for(int i=0;i<lim;i++)a[i]=(a[i]*iv%mod+mod)%mod;
	}
}
node operator *(node a,node b){
	node ans;
	for(int i=0;i<=k;i++)
		a[i]=a[i]*ij[i]%mod,b[i]=b[i]*ij[i]%mod;
	ntt(a.a),ntt(b.a);
	for(int i=0;i<lim;i++)
		ans[i]=a[i]*b[i]%mod;
	ntt(ans.a,-1);
	for(int i=0;i<=k;i++)
		ans[i]=ans[i]*jc[i]%mod;
	for(int i=k+1;i<lim;i++)
		ans[i]=0; 
	return ans; 
} 

void solve(){
	cin>>n>>m>>k;
	init();
	res[0]=1;
	A[0]=1;for(int i=1;i<=k;i++)A[i]=inv(m);
	for(int i=1;i<=n;i<<=1,A=A*A)
		if(n&i)
			res=res*A;
	cout<<res[k]<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}