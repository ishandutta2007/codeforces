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
const int MAXN=5e5+10,base=10,LIM=5e6;
bool tag[LIM+10];
int prime[LIM+10],prime2[LIM+10],tot,m;
int mod[3];
char s[MAXN],x[MAXN];
int n1,n2;
ll num[3],h[3][MAXN],power[3][MAXN];
char tmp[MAXN*2];
int z[MAXN*2],len;
void pre(){
	rep(i,2,LIM){
		if(!tag[i]){
			prime[++tot]=i;
			if(i>1e6)prime2[++m]=i;
		}
		rep(j,1,tot){
			if(prime[j]*i>LIM)break;
			tag[prime[j]*i]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int getrand(int mod){
	int ret=1;
	rep(i,1,100)ret=1ll*ret*rand()%mod;
	return ret;
}
ll geth(int idx,int l,int r){
	return (h[idx][r]-h[idx][l-1]*power[idx][r-l+1]%mod[idx]+mod[idx])%mod[idx];
}
int check(int i,int j,int k){
	rep(idx,0,2){
		if((geth(idx,i,j)+geth(idx,j+1,k))%mod[idx]!=num[idx])return 0;
	}
	return 1;
}
void Z(char* s,int n){
	z[1]=n;
	int pos=0,r=0;
	rep(i,2,n){
		if(r<i){ 
			r=i-1;pos=i;
			while(s[i+z[i]]==s[1+z[i]])z[i]++,r++;
			continue;
		}
		int j=i-pos+1;
		if(i+z[j]-1<r){z[i]=z[j];continue;}
		z[i]=r-i+1;
		pos=i;
		while(s[i+z[i]]==s[1+z[i]])z[i]++,r++;
		
	}
}
int main(){
	srand(time(0));
	pre();
	mod[0]=prime2[getrand(m)+1];mod[1]=prime2[getrand(m)+1];mod[2]=prime2[getrand(m)+1];
	scanf("%s%s",s+1,x+1);
	n1=strlen(s+1);n2=strlen(x+1);
	rep(i,0,2)rep(j,1,n2){num[i]=(num[i]*base+x[j]-'0')%mod[i];}
	rep(i,0,2)rep(j,1,n1){h[i][j]=(h[i][j-1]*base+s[j]-'0')%mod[i];}
	rep(i,0,2){
		power[i][0]=1;
		rep(j,1,n1){
			power[i][j]=power[i][j-1]*base%mod[i];
		}
	}
	rep(i,1,n2)tmp[++len]=x[i];
	tmp[++len]='#';
	rep(i,1,n1)tmp[++len]=s[i];
	Z(tmp,len);
	rep(i,1,n1){
		if(i+(n2-1)*2-1<=n1){
			if(check(i,i+(n2-1)-1,i+(n2-1)*2-1)){
				printf("%d %d\n%d %d\n",i,i+(n2-1)-1,i+(n2-1),i+(n2-1)*2-1);return 0;
			}
		}
	}
	rep(i,1,n1){
		if(i+n2-1<=n1){
			int lcp=z[n2+1+i];
			if(lcp==n2)continue;
			int l=n2-lcp;
			if(i+n2+l-1<=n1){
				if(check(i,i+n2-1,i+n2+l-1)){
					printf("%d %d\n%d %d\n",i,i+n2-1,i+n2,i+n2+l-1);
					return 0;
				}
			}
			if(i-l>=1){
				if(check(i-l,i-1,i+n2-1)){
					printf("%d %d\n%d %d\n",i-l,i-1,i,i+n2-1);
					return 0;
				}
			}
			l--;
			if(l==0)continue;
			if(i+n2+l-1<=n1){
				if(check(i,i+n2-1,i+n2+l-1)){
					printf("%d %d\n%d %d\n",i,i+n2-1,i+n2,i+n2+l-1);
					return 0;
				}
			}
			if(i-l>=1){
				if(check(i-l,i-1,i+n2-1)){
					printf("%d %d\n%d %d\n",i-l,i-1,i,i+n2-1);
					return 0;
				}
			}
		}
	}
	return 0;
}