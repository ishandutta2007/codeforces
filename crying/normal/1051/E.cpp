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
const int MAXN=1e6+10,mod=998244353;
char a[MAXN],L[MAXN],R[MAXN];
char tmps[MAXN*2];
int n,k1,k2;
int lcpl[MAXN],lcpr[MAXN],tmp[MAXN*2];
int f[MAXN],sum[MAXN];
void exkmp(char* s,int n,int* z){
	z[1]=n;
	int pos=0,r=0;
	rep(i,2,n){
		z[i]=0;
		if(r<i){
			pos=i;r=i-1;
			while(r<n && s[r+1]==s[r-i+2])r++,z[i]++;
			continue;
		}
		int j=i-pos+1;
		if(i+z[j]-1 < r){
			z[i]=z[j];
			continue;
		}
		pos=i;
		z[i]=r-i+1;
		while(r<n && s[r+1]==s[r-i+2])r++,z[i]++;
	}
}
void dp(){
	f[0]=1;if(a[1]>'0')sum[0]=1;
	rep(i,1,n){
		//(k1,k2)
		int l=i-(k2-1),r=i-(k1+1);
		l=max(l,0);r=min(r,i-1); //[l,r]&[0,n-1]
		if(l<=r){
			f[i]=sum[r];
			if(l>0)f[i]=(f[i]-sum[l-1]+mod)%mod;
		}
		if(k1==k2){
			int l=i-k1,flag=1;
			if(l<0)flag=0;
			else{
				if(lcpl[l+1]!=k1 && L[lcpl[l+1]+1]>a[l+lcpl[l+1]+1])flag=0;
				if(lcpr[l+1]!=k2 && R[lcpr[l+1]+1]<a[l+lcpr[l+1]+1])flag=0;
				if(a[l+1]=='0' && k1>1)flag=0;
			}
			if(flag)f[i]=(f[i]+f[l])%mod;
		}else{
			int l=i-k1,flag=1;
			if(l<0)flag=0;
			else{
				if(lcpl[l+1]!=k1 && L[lcpl[l+1]+1]>a[l+lcpl[l+1]+1])flag=0;
				if(a[l+1]=='0' && k1>1)flag=0;
			}
			if(flag)f[i]=(f[i]+f[l])%mod;
			int r=i-k2;flag=1;
			if(r<0)flag=0;
			else{
				if(lcpr[r+1]!=k2 && R[lcpr[r+1]+1]<a[r+lcpr[r+1]+1])flag=0;
				if(a[r+1]=='0')flag=0;
			}
			if(flag)f[i]=(f[i]+f[r])%mod;
		}
		sum[i]=sum[i-1];
		if(a[i+1]!='0')sum[i]=(sum[i]+f[i])%mod;
	//	printf("f[%d]:%d\n",i,f[i]);
	}
}
int main(){
	scanf("%s%s%s",a+1,L+1,R+1);
	n=strlen(a+1);k1=strlen(L+1);k2=strlen(R+1);
	rep(i,1,k1)tmps[i]=L[i];
	tmps[k1+1]='#';
	rep(i,1,n)tmps[k1+1+i]=a[i];
	exkmp(tmps,k1+n+1,tmp);
	rep(i,k1+2,k1+n+1)lcpl[i-k1-1]=tmp[i];
	rep(i,1,k2)tmps[i]=R[i];
	tmps[k2+1]='#';
	rep(i,1,n)tmps[k2+1+i]=a[i];
	exkmp(tmps,k2+n+1,tmp);
	rep(i,k2+2,k2+n+1)lcpr[i-k2-1]=tmp[i];
	dp();
	printf("%d",f[n]);
	return 0;
}