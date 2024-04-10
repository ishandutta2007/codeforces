#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef vector<int> vin;
typedef vector<i64> v64;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls(x) ((x)<<1)
#define rs(x) (((x)<<1)|1)
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
int a[30];
int lst=0;
int main(){
	int cnt=0;
	rep(i,2,100){
		int v=sqrt(i);bool flag=1;
		rep(x,2,v)if(i%x==0)flag=0;cnt+=flag;
		if(flag)a[cnt]=i,cerr<<i<<endl;
	}int res=0;
	rep(i,1,15){
		printf("%d\n",a[i]);
		fflush(stdout);
		char s[10];
		scanf("%s",s+1);
		if(s[1]=='y')res++,lst=a[i];
	}
	if(res>=2){puts("composite");fflush(stdout);return 0;}
	if(res==1){
		if(lst<10){
		printf("%d\n",lst*lst);
		fflush(stdout);
		char s[10];
		scanf("%s",s+1);
		if(s[1]=='y'){puts("composite");fflush(stdout);return 0;}
		else{
			puts("prime");fflush(stdout);return 0;
		}}
		else{
			puts("prime");fflush(stdout);
		}
	}
	else puts("prime");fflush(stdout);
	return 0;
}