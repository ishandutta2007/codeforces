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
const int maxn=200005;
char s[maxn];
int n;
vector<int> ans[maxn];
int nd;
set<int> v0,v1;
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	rep(i,1,n){
		if(s[i]=='0'){
			if(v1.size()){
				int tmp=*(v1.begin());
				// cerr<<tmp<<endl;
				ans[tmp].pb(i);
				v1.erase(tmp);
				v0.insert(tmp);
			}else{
				nd++;
				ans[nd].pb(i);
				v0.insert(nd);
			}
		}else{
			if(v0.size()){
				int tmp=*v0.begin();
				ans[tmp].pb(i);
				v0.erase(tmp);
				v1.insert(tmp);
			}else{
				puts("-1");
				return 0;
			}
		}
	}
	if(v1.size()){
		puts("-1");
		return 0;
	}
	printf("%d\n",nd);
	rep(i,1,nd){
		printf("%d ",ans[i].size());
		for(u32 j=0;j<ans[i].size();j++)
			printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}