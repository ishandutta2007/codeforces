#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2e5+10,LIM=2e5;
int n,a[MAXN],b[MAXN],q,x;
int tag[MAXN],prime[MAXN],miu[MAXN],tot;
ll c[MAXN],f[MAXN];
ll arr[3][MAXN],len[3],sum[3][MAXN];
void pre(){
	miu[1]=1;
	rep(i,2,LIM){
		if(!tag[i]){prime[++tot]=i;miu[i]=-1;}
		rep(j,1,tot){
			if(prime[j]*i>LIM)break;
			tag[i*prime[j]]=1;
			if(i%prime[j]==0){
				miu[i*prime[j]]=0;
				break;
			}else{
				miu[i*prime[j]]=miu[i]*(-1);
			}
		}
	} 
}
int main(){
	pre();
	scanf("%d",&n);
	rep(i,1,n){scanf("%d",&a[i]);}
	rep(i,1,n){scanf("%d",&b[i]);c[i]=a[i]-b[i];}
	rep(i,2,n){
		rep(j,1,n){
			if(i*j>n)break;
			f[i*j]+=miu[j]*c[i];
		}
	}
	rep(i,2,n){
		arr[miu[i]+1][++len[miu[i]+1]]=f[i];
	}
	rep(i,0,2)sort(arr[i]+1,arr[i]+1+len[i]);
	rep(i,0,2){
		rep(j,1,len[i])sum[i][j]=sum[i][j-1]+(i==1?abs(arr[i][j]):arr[i][j]);
	}
	scanf("%d",&q);
	rep(i,1,q){
		scanf("%d",&x);
		ll c=a[1]-x,ans=sum[1][len[1]]+abs(c);
		//miu(i)=-1
		int pos=lower_bound(arr[0]+1,arr[0]+1+len[0],c)-arr[0];
		if(pos<=len[0])ans+=(sum[0][len[0]]-sum[0][pos-1])-c*(len[0]-pos+1);
		if(pos>=1)ans+=c*(pos-1)-sum[0][pos-1];
		//miu(i)=1 
		pos=lower_bound(arr[2]+1,arr[2]+1+len[2],-c)-arr[2];
		if(pos<=len[2])ans+=(sum[2][len[2]]-sum[2][pos-1])+c*(len[2]-pos+1);
		if(pos>=1)ans+=-c*(pos-1)-sum[2][pos-1];
		printf("%lld\n",ans);
	}

	return 0;
}