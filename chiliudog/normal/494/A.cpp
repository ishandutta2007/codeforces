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
int n,sum;
int a[maxn],ans[maxn];
int main(){
    scanf("%s",s+1);n=strlen(s+1);
    rep(i,1,n){
    	if(s[i]=='('){
    		a[i]=1;
    	}
    	if(s[i]==')'){
    		a[i]=-1;
    	}
    	if(s[i]=='#'){
    		a[i]=-1;ans[i]=1;
    	}
    	sum+=a[i];
    }
    if(sum<0){
    	puts("-1");return 0;
    }
    per(i,n,1){
    	if(s[i]=='#'){
    		a[i]-=sum;ans[i]+=sum;
    		break;
    	}
    }sum=0;
    rep(i,1,n){
    	sum+=a[i];
    	if(sum<0){
    		puts("-1");return 0;
    	}
    }
    if(sum!=0){
    	assert(0);
    }
    rep(i,1,n){
    	if(ans[i])printf("%d\n",ans[i]);
    }
    return 0;
}