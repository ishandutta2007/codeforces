#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<cassert>
#include<queue>
#include<cmath>
#include<queue>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=100005;
char s[maxn];
string qs[maxn];
char t[maxn];
// int nxt[maxn];
int nxt[maxn],n,m,len,qk[maxn],id[maxn];
int pw1[maxn],pw2[maxn],ans[maxn];
int pos[maxn],postot;
pair<int,int> s1[maxn],s2[maxn];
const int seed1=31,mod1=998244353;
const int seed2=29,mod2=1e9+9;
const int Block=100;
inline bool cmp(const int &a,const int &b){
	return qs[a].length()<qs[b].length();
}
inline int powmod(int a,int b,int mod){
	int res=1;for(;b;b>>=1){
		if(b&1)res=1ll*res*a%mod;
		a=1ll*a*a%mod;
	}return res;
}
inline int solve(int k){
	len=strlen(t+1);
	postot=0;
	int j=0;
	rep(i,2,len){
		while(j&&t[j+1]!=t[i])j=nxt[j];
		if(t[j+1]==t[i])j++;nxt[i]=j;
	}j=0;
	rep(i,1,n){
		while(j&&t[j+1]!=s[i])j=nxt[j];
		if(t[j+1]==s[i])j++;
		if(j==len){
			pos[++postot]=i;
			j=nxt[j];
		}
	}int mini=1e9;
	rep(i,1,postot-k+1){
		mini=min(mini,pos[i+k-1]-pos[i]+len);
	}
	return mini;
}
inline void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	read(m);
	pw1[0]=pw2[0]=1;
	rep(i,1,n){
		pw1[i]=1ll*pw1[i-1]*seed1%mod1;
		pw2[i]=1ll*pw2[i-1]*seed2%mod2;
	}
	rep(i,1,m){
		cin>>qk[i];
		cin>>qs[i];
		id[i]=i;
	}
	sort(id+1,id+1+m,cmp);
	int tot=0;
	rep(i,1,m){
		tot++;
		int j=i;
		while(j<m&&qs[id[j]].length()==qs[id[j+1]].length())j++;
		int tot1=0,tot2=0,leng=qs[id[i]].length();
		if(leng>Block){
			rep(k,i,j){
				// cerr<<k<<endl;
				len=qs[id[k]].length();
				rep(p,1,len)t[p]=qs[id[k]][p-1];
				ans[id[k]]=solve(qk[id[k]]);
				if(ans[id[k]]==1e9)ans[id[k]]=-1;
			}
			i=j;
			continue;
		}
		int v1=0,v2=0;
		rep(k,1,n){
			v1=(1ll*v1*seed1+(s[k]-'a'))%mod1;
			// v2=(1ll*v2*seed2+(s[k]-'a'))%mod2;
			if(k>=leng){
				s1[++tot1]=mk(v1,k);
				v1=(v1-1ll*(s[k-leng+1]-'a')*pw1[leng-1]%mod1+mod1)%mod1;
				// v2=(v2-1ll*(s[k-leng+1]-'a')*pw2[leng-1]%mod2+mod2)%mod2;
			}
		}
		rep(k,i,j){
			int x=id[k];
			int v1=0,v2=0;
			for(u32 l=0;l<qs[x].length();l++){
				v1=(1ll*v1*seed1+(qs[x][l]-'a'))%mod1;
				// v2=(1ll*v2*seed2+(qs[x][l]-'a'))%mod2;
			}
			s2[++tot2]=mk(v1,x);
		}
		sort(s1+1,s1+tot1+1);
		sort(s2+1,s2+tot2+1);
		int cur=1;
		rep(k,1,tot2){
			while(cur<=tot1&&s1[cur].w1<s2[k].w1)cur++;
			int nxt=cur-1;
			while(nxt<tot1&&s1[nxt+1].w1==s2[k].w1)nxt++;
			int mini=1e9;
			// cerr<<cur<<' '<<nxt<<endl;
			// cerr<<s1[1].w2<<endl;
			// cerr<<s1[2].w2<<endl;
			// cerr<<s1[3].w2<<endl;
			// cerr<<s1[4].w2<<endl;
			// cerr<<s1[5].w2<<endl;
			// cerr<<qk[s2[k].w2]<<endl;
			rep(i,cur,nxt){
				if(i+qk[s2[k].w2]-1>nxt)break;
				mini=min(mini,s1[i+qk[s2[k].w2]-1].w2-s1[i].w2+(int)qs[s2[k].w2].length());
			}
			ans[s2[k].w2]=mini;
			if(mini==1e9)ans[s2[k].w2]=-1;
			cur=nxt+1;
		}
		i=j;
	}
	assert(tot<=1000);
	rep(i,1,m)printf("%d\n",ans[i]);
}
int main(){
	solve();
	return 0;
}