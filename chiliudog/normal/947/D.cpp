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
char s[maxn],t[maxn];
int sum1[maxn],sum2[maxn],n,m,l[maxn],l2[maxn];
int main(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);m=strlen(t+1);
	rep(i,1,n)sum1[i]=sum1[i-1]+(s[i]=='B'||s[i]=='C');
	rep(i,1,m)sum2[i]=sum2[i-1]+(t[i]=='B'||t[i]=='C');
	rep(i,1,n){
		if(s[i]=='A')l[i]=l[i-1];else l[i]=i;
	}
	rep(i,1,m){
		if(t[i]=='A')l2[i]=l2[i-1];else l2[i]=i;
	}
	int q;read(q);
	while(q--){
		int a,b,c,d;read(a);read(b);read(c);read(d);
		int res1=sum1[b]-sum1[a-1],res2=sum2[d]-sum2[c-1];
		if((res1&1)!=(res2&1)){
			putchar('0');
			continue;
		}
		if(res1>res2){
			putchar('0');
			continue;
		}
		int v=(b-max(a-1,l[b]));
		int v2=(d-max(c-1,l2[d]));
		if(v<v2){
			putchar('0');
			continue;
		}
		if(res1<res2){
			if(v==v2&&(res1==0))
			putchar('0');
		else putchar('1');
			continue;
		}
		if(res1==res2){
			if(v%3!=v2%3){
				putchar('0');
			}else{
				putchar('1');
			}
		}
	}
	return 0;
}