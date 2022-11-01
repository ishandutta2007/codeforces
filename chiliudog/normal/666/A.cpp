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
int n;
bool flag[maxn][4];
set<string> ans;
int main(){
	scanf("%s",s+1);n=strlen(s+1);flag[n+1][2]=1;flag[n+1][3]=1;
	s[n+1]='0';s[n+2]='0';s[n+3]='0';
	per(i,n,1){
		if(!flag[i+1])continue;
		if(i>=7){	
			string s1="",s2="";
			rep(k,i-1,i)s1=s1+s[k];
			rep(k,i+1,i+2)s2=s2+s[k];
			if((s1!=s2&&flag[i+1][2])||flag[i+1][3]){
				flag[i-1][2]=1;ans.insert(s1);
			}
		}
		if(i>=8){
			string s1="",s2="";
			rep(k,i-2,i)s1=s1+s[k];
			rep(k,i+1,i+3)s2=s2+s[k];
			if((s1!=s2&&flag[i+1][3])||flag[i+1][2]){
				flag[i-2][3]=1;ans.insert(s1);
			}
		}
	}
	printf("%d\n",(int)ans.size());
	for(string v:ans)printf("%s\n",v.c_str());
	return 0;
}