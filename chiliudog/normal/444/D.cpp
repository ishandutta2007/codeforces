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
const int seed=31,mod=998244353;
int n;
map<int,int> id;
vector<int> a[maxn<<2];
int bl[maxn][4];
int whx[maxn<<2];
map<int,int> zhong;
int block,cnt,tot;
typedef map<int,int>::iterator It;
int ans[126][maxn<<2];
inline void calc(int len){
	bool flag[maxn];
	rep(i,1,n-len+1){
		int v=0;
		rep(j,i,i+len-1)v=v*31+s[j]-'a'+1;
		int x=(id.count(v)?(id[v]):(id[v]=++cnt));
		if(x==cnt)whx[x]=len;
		bl[i][len]=x;
		a[x].pb(i);
		if(a[x].size()==block){
			zhong[x]=++tot;
		}
	}
}
inline int calc(int a1,int len1,int a2,int len2){
	return max(a1+len1-1,a2+len2-1)-min(a1,a2)+1;
}
inline void update(int x,int y,int v){
	if(ans[zhong[x]][y]){
		ans[zhong[x]][y]=min(ans[zhong[x]][y],v);
	}else{
		ans[zhong[x]][y]=v;
	}
}
inline void gao(int len,int place,int v,int x){
	if(v<a[x].size()){
		update(x,bl[place][len],calc(place,len,a[x][v],whx[x]));
	}
	if(v>0){
		update(x,bl[place][len],calc(place,len,a[x][v-1],whx[x]));
	}
}
inline void prprpr(){
	for(It it=zhong.begin();it!=zhong.end();it++){
		int id=it->w1,p=it->w2;
		rep(len,1,4){
			int nowv=0;
			rep(i,1,n-len+1){
				gao(len,i,nowv,id);
				if(a[id][nowv]==i)nowv++;
			}
		}
	}
}
const int inf=1<<29;
inline int query(int x,int y){
	if(a[x].size()<a[y].size())swap(x,y);
	if(a[x].size()>=block)return ans[zhong[x]][y];
	int res=inf,len1=whx[x],len2=whx[y];
	if(x==y)return len1;
	int n=a[x].size(),m=a[y].size();
	int i=0,j=0,lastx=-1,lasty=-1;
	rep(_,1,n+m)
		if((j==m)||(i<n&&a[x][i]<a[y][j])){
			if(lasty!=-1)res=min(res,calc(a[x][i],len1,lasty,len2));
			lastx=a[x][i++];
		}else{
			if(lastx!=-1)res=min(res,calc(a[y][j],len2,lastx,len1));
			lasty=a[y][j++];
		}
	return res;
}
char s1[20],s2[20];
inline void solve(){
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	int n=strlen(s1+1),m=strlen(s2+1);
	int v1=0,v2=0,x,y;
	rep(i,1,n)v1=1ll*seed*v1+s1[i]-'a'+1;	
	rep(i,1,m)v2=1ll*seed*v2+s2[i]-'a'+1;
	if(!(id.count(v1)&&id.count(v2))){
		printf("-1\n");
		return;
	}
	x=id[v1];y=id[v2];
	printf("%d\n",query(x,y));
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);block=800;
	rep(i,1,4)calc(i);
	prprpr();
	int m;read(m);
	while(m--)solve();
	return 0;
}