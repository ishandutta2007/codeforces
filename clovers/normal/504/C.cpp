#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int N=150000;
const ll MOD1=998244353;
const ll MOD2=(ll)1e9+7;
ll qpow(ll x,ll y,ll MOD)
{
	ll ret=1;
	while(y)
	{
		if(y&1) ret=ret*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return ret;
}

ll a[N],cnt[N],suml_1[N],suml_2[N],sumr_1[N],sumr_2[N],tmp[N],ans=0;
int n;
bool check(int l,int r,int L,int R)//l~r  L~R(r<L)
{
	//cout<<"O:"<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
	if(r<1||L>n) return 1;
	ll suml1=(suml_1[r]-suml_1[l-1]+MOD1)%MOD1;
	ll suml2=(suml_2[r]-suml_2[l-1]+MOD2)%MOD2;
	ll sumr1=(sumr_1[L]-sumr_1[R+1]+MOD1)%MOD1;
	ll sumr2=(sumr_2[L]-sumr_2[R+1]+MOD2)%MOD2;
	//cout<<l<<" "<<r<<" "<<suml1<<" "<<sumr1<<endl;
	return suml1==sumr1&&suml2==sumr2;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]); cnt[a[i]]++;
		suml_1[i]=(suml_1[i-1]+a[i]*qpow(n,i-1,MOD1)%MOD1)%MOD1;
		suml_2[i]=(suml_2[i-1]+a[i]*qpow(n,i-1,MOD2)%MOD2)%MOD2;
		//cout<<sum1[i]<<endl;
	}
	for(int i=n;i>=1;i--)
	{
		sumr_1[i]=(sumr_1[i+1]+a[i]*qpow(n,n-i,MOD1)%MOD1)%MOD1;
		sumr_2[i]=(sumr_2[i+1]+a[i]*qpow(n,n-i,MOD2)%MOD2)%MOD2;
	}
	//cout<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<endl;
	int limit_l=n,limit_r=1;//l=1~limit_l  r=limit_r~n
	int bl=0;
	for(int i=0;i<N;i++) if(cnt[i]%2==1) bl++;
	if(bl>1)
	{
		puts("0");
		return 0;
	}
	int add=0,mx=0;
	for(int i=1;i<(1+n+1)/2;i++)
	{
		tmp[a[i]]++;
		if(tmp[a[i]]*2>cnt[a[i]])
		{
			if(limit_l==n) limit_l=i;
			add++;
		}
	}
	mx=add;
	memset(tmp,0,sizeof(tmp));
	add=0;
	for(int i=n;i>(1+n)/2;i--)
	{
		tmp[a[i]]++;
		if(tmp[a[i]]*2>cnt[a[i]])
		{
			if(limit_r==1) limit_r=i;
			add++;
		}
	}
	mx=max(mx,add);
	//cout<<mx<<endl;
	int ju=0;
	if(limit_l!=n||limit_r!=1) ju=1;
	if(ju) limit_l=min(limit_l,(n+1)/2+1-mx);
	for(int i=1;i<=limit_l;i++)//l=i
	{
		int l=max(limit_r,i),r=n,mid,best=-1;//r=best~r
		//cout<<l<<endl;
		if(ju) l=max(l,n/2+mx);
		while(l<=r)
		{
			mid=(l+r)>>1; int bl=1;
			//cout<<mid<<endl;
			if(mid<n/2&&i<n/2) 
			{
				int len=n/2-mid;
				int r_l=(n+1)/2+1;
				bl=check(mid+1,n/2,r_l,r_l+len-1);
				//if(mid==2) cout<<mid+1<<" "<<n/2<<" "<<r_l<<" "<<r_l+len-1<<endl;
			}
			if(i>(n+1)/2+1)
			{
				int len=i-((n+1)/2+1);
				int l_r=n/2;
				bl=check(l_r-len+1,l_r,((n+1)/2+1),i-1);
			}
			//if(mid<n/2) cout<<mid<<" "<<bl<<endl;
			int L=i-1,R=mid+1;
			int len=min(L,n-R+1);
			L=len; R=n-len+1;
			if(check(1,L,R,n)&&bl)
			{
				r=mid-1;
				best=mid;
			}
			else l=mid+1;
		}
		//cout<<i<<" "<<best<<endl;
		if(best!=-1) ans+=n-best+1;
	}
	cout<<ans<<endl;
	return 0;
}