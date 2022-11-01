#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b)
#define w1 first
#define w2 second
typedef pair<int,int> pin;
const int maxn=100005;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int cnt[maxn],sum[maxn];
int l[maxn],r[maxn],q[maxn],a[maxn],n,m;
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
inline bool solve(int k){
	memset(cnt,0,sizeof(cnt));
	rep(i,1,m)if(q[i]&(1<<k))cnt[l[i]]++,cnt[r[i]+1]--;
	rep(i,1,n)cnt[i]+=cnt[i-1],a[i]|=(cnt[i]!=0)<<k,sum[i]=sum[i-1]+(cnt[i]==0);
	rep(i,1,m)if((!(q[i]&(1<<k)))&&(sum[r[i]]-sum[l[i]-1]==0))return 1;
	return 0;
}
int main(){
	read(n);read(m);
	rep(i,1,m)read(l[i]),read(r[i]),read(q[i]);
	rep(i,0,29)if(solve(i)){
		puts("NO");return 0;
	}puts("YES");
	rep(i,1,n)printf("%d ",a[i]);
    return 0;
}