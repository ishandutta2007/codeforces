#include<bits/stdc++.h>
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
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
#define dg(...) fprintf(stderr,__VA_ARGS__);
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
const int maxn=5005;
using namespace std;
struct bian{
	int next,point;
}b[maxn];
int p[maxn],n,m,len,pd[maxn],in[maxn],s[maxn],head,dfs[maxn],low[maxn],num[maxn],sign,now,w[maxn],bo[maxn];
inline void addedge(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
inline void dfs1(int k1){
	s[++head]=k1; pd[k1]=1; in[k1]=1; dfs[k1]=++sign; low[k1]=sign;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (pd[j]==0){
			dfs1(j); low[k1]=min(low[k1],low[j]);
		} else if (in[j]) low[k1]=min(low[k1],dfs[j]);
	}
	if (low[k1]==dfs[k1]){
		now++;
		while (s[head+1]!=k1){
			in[s[head]]=0; num[s[head]]=now; head--;
		}
	}
}
queue<int>Q;
inline int get(int k){
	memset(bo,0x00,sizeof bo); 
	while (!Q.empty()) Q.pop(); Q.push(k);
	bo[k]=1;
	while (!Q.empty()){
		int k1=Q.front();
		for (int i=p[k1];i;i=b[i].next){
			int j=b[i].point;
			if (bo[j]==0){
				bo[j]=bo[k1]+1; Q.push(j);
			} else if (j==k) return bo[k1];
		}
		Q.pop();
	}
	return 0;
}
int main(){
	read(n);read(m);
	rep(i,1,m){
		int k1,k2;read(k1);read(k2);addedge(k1,k2);
	}
	rep(i,1,n)if (pd[i]==0) dfs1(i);
	memset(pd,0x00,sizeof pd);
	rep(k,1,n)
		for (int i=p[k];i;i=b[i].next){
			int j=b[i].point;
			if (num[k]!=num[j]) pd[num[k]]=1;
		}
	memset(w,0x3f,sizeof w);
	rep(i,1,n){
		w[num[i]]=min(w[num[i]],get(i));
	}
	int ans=n;
	rep(i,1,now)
		if (pd[i]==0&&w[i]){
			ans++; ans+=w[i]*998;
		}
	cout<<ans<<endl;
	return 0;
}