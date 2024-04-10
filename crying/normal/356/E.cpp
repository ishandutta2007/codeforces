#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
const int MAXN=1e5+10,base=13331;
int n,valid[MAXN][27];
int bucket[MAXN][27]; // 
char s[MAXN];
ull power[MAXN],preh[MAXN]; //hash
ll w[MAXN],g[MAXN][27]; //
ll ans; 
il ull gethash(int i,int j){
	//hash(S[i..j])
	if(i>j)return 0;
	return preh[j]-preh[i-1]*power[j-i+1];
}
il int getcnt(int i,int j,char ch){
	//chS[i..j]
	if(i>j)return 0;
	return bucket[j][ch-'a'+1]-bucket[i-1][ch-'a'+1]; 
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	power[0]=1;
	rep(i,1,n){
		preh[i]=preh[i-1]*base+(s[i]-'a'+1);
		power[i]=power[i-1]*base;
		rep(j,1,26)bucket[i][j]=bucket[i-1][j];
		bucket[i][s[i]-'a'+1]++;
	}
	//gray
	rep(i,1,n)valid[i][1]=1;
	rep(k,2,29){
		rep(i,1,n){
			if(i+(1<<k)-2>n)break;
			int j=i+(1<<k)-2;int mid=(i+j)/2; 
			valid[i][k]=(getcnt(i,j,s[mid])==1) && (valid[i][k-1] && valid[mid+1][k-1]) && 
			(gethash(i,mid-1)==gethash(mid+1,j));
		}
	} 
	//w
	rep(i,1,n){
		rep(k,1,19){
			int len=(1<<k)-1;
			int j=i+len-1;
			if(valid[i][k])ans+=(ll)len*len,w[i]+=(ll)len*len,w[j+1]-=(ll)len*len;
		}
	} 
	rep(i,1,n)w[i]+=w[i-1];
	//g 
	rep(i,1,n){
		rep(j,1,26){g[i][j]++;} //1 
		rep(k,2,19){
			int len=(1<<k)-1;int j=i+len-1;int mid=(i+j)/2;
			if(j>n)break;
			//s[i...j]gray 
			if(gethash(i,mid-1)==gethash(mid+1,j)){
				// 
				if(valid[i][k-1] && valid[mid+1][k-1]){
					rep(x,1,26){
						if(!getcnt(i,mid-1,'a'+x-1))g[mid][x]+=(ll)len*len;
					} 
				}
			}else{
				//
				//
				int L=1,R=(1<<(k-1))-1,ret=0;
				while(L<=R){
					int MID=(L+R)>>1;
					if(gethash(i,i+MID-1)!=gethash(mid+1,mid+MID)){
						ret=MID;
						R=MID-1;
					}else{
						L=MID+1;
					}
				}
			//	printf("%d%d\n",i+ret-1,mid+ret);
			//	printf("[%llu,%llu]\n",gethash(i+ret,mid-1),gethash(mid+ret+1,j));
				//s[i+ret-1]s[mid+ret] 
				if(gethash(i+ret,mid-1) != gethash(mid+ret+1,j))continue;
				
				//1.
				if(valid[mid+1][k-1]){
					if(!getcnt(mid+1,j,s[mid]))g[i+ret-1][s[mid+ret]-'a'+1]+=(ll)len*len;
				} 
				//2.
				if(valid[i][k-1]){
					if(!getcnt(i,mid-1,s[mid]))g[mid+ret][s[i+ret-1]-'a'+1]+=(ll)len*len;
				} 
			}
		}
	} 
	
	ll t=0;
	rep(i,1,n){
		ll tmp=ans;
		rep(j,1,26)tmp=Max(tmp,ans-w[i]+g[i][j]);
		t=Max(t,tmp);
	}
	ans=t;
	
	printf("%lld",ans);
	return 0;
}
/*
dsjasdjqwz
*/