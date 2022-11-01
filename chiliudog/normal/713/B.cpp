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
const int maxn=10005;
typedef pair<pin,pin> rec;
int cnt=0;
inline void TLE(){for(;;);}
inline rec findd(int l,int r,int u,int d){
	if(l>r)TLE();if(u>d)TLE();
	int xl=1,xr=-1,yl=1,yr=-1;
//	printf("\n", );
	int el=l,er=r;
	while(el<=er){
		int md=(el+er)>>1;
		printf("? %d %d %d %d\n",u,md,d,r);
		cnt++;//if(cnt>200)TLE();
		fflush(stdout);
		int res;read(res);
//		if(res==2)TLE();
		if(res)
			xl=md,el=md+1;
		else
			er=md-1;
	}el=l;er=r;
	while(el<=er){
		int md=(el+er)>>1;
		printf("? %d %d %d %d\n",u,l,d,md);
		cnt++;//if(cnt>200)TLE();
		fflush(stdout);
		int res;read(res);
//		if(res==2)TLE();
		if(res)
			xr=md,er=md-1;
		else
			el=md+1;
	}el=u;er=d;
	while(el<=er){
		int md=(el+er)>>1;
		printf("? %d %d %d %d\n",md,l,d,r);
		cnt++;//if(cnt>200)TLE();
		fflush(stdout);
		int res;read(res);
		// if(res==2)TLE();
		if(res)
			yl=md,el=md+1;
		else
			er=md-1;
	}el=u;er=d;
	while(el<=er){
		int md=(el+er)>>1;
		printf("? %d %d %d %d\n",u,l,md,r);
		cnt++;//if(cnt>200)TLE();
		fflush(stdout);
		int res;read(res);
		// if(res==2)TLE();
		if(res)
			yr=md,er=md-1;
		else
			el=md+1;
	}
//	if(xl>xr)TLE();if(yl>yr)TLE();
	return mk(mk(yl,xl),mk(yr,xr));
}
inline rec find(int u,int l,int d,int r){
	return findd(l,r,u,d);
}
int main(){
//	judge();
	int n;read(n);
	int l=1,r=n-1;
	while(l<=r){
		int md=(l+r)>>1;
		printf("? %d %d %d %d\n",1,1,md,n);
		cnt++;//if(cnt>200)TLE();
		fflush(stdout);
		int x;read(x);
		if(x==0){
			l=md+1;continue;
		}
		printf("? %d %d %d %d\n",md+1,1,n,n);
		cnt++;//if(cnt>200)TLE();
		fflush(stdout);
		int y;read(y);
		if(x==1&&y==1){
			rec rec1=find(1,1,md,n);
			rec rec2=find(md+1,1,n,n);
			printf("! %d %d %d %d %d %d %d %d\n",rec1.w1.w1,rec1.w1.w2,rec1.w2.w1,rec1.w2.w2,rec2.w1.w1,rec2.w1.w2,rec2.w2.w1,rec2.w2.w2);
			fflush(stdout);
			return 0;
		}
/*		if(x==1&&y==2){
			rec rec1=find(1,1,md,n);
			rec rec2=find(md+1,1,n,n);
			printf("! %d %d %d %d %d %d %d %d\n",rec1.w1.w1,rec1.w1.w2,rec1.w2.w1,rec1.w2.w2,rec2.w1.w1,rec2.w1.w2,rec2.w2.w1,rec2.w2.w2);
			fflush(stdout);
			return 0;
		}
		if(x==2&&y==1){
			rec rec1=find(1,1,md-1,n);
			rec rec2=find(md,1,n,n);
			printf("! %d %d %d %d %d %d %d %d\n",rec1.w1.w1,rec1.w1.w2,rec1.w2.w1,rec1.w2.w2,rec2.w1.w1,rec2.w1.w2,rec2.w2.w1,rec2.w2.w2);
			fflush(stdout);
			return 0;
		}*/
		r=md-1;
	}
	l=1,r=n-1;
		while(l<=r){
			int md=(l+r)>>1;
			printf("? %d %d %d %d\n",1,1,n,md);
		cnt++;//if(cnt>200)TLE();
			fflush(stdout);
			int x;read(x);
			if(x==0){
				l=md+1;continue;
			}
			printf("? %d %d %d %d\n",1,md+1,n,n);
		cnt++;//if(cnt>200)TLE();
			fflush(stdout);
			int y;read(y);
			if(x==1&&y==1){
				rec rec1=find(1,1,n,md);
				rec rec2=find(1,md+1,n,n);
				printf("! %d %d %d %d %d %d %d %d\n",rec1.w1.w1,rec1.w1.w2,rec1.w2.w1,rec1.w2.w2,rec2.w1.w1,rec2.w1.w2,rec2.w2.w1,rec2.w2.w2);
				fflush(stdout);
				return 0;
			}
/*			if(x==1&&y==2){
				rec rec1=find(1,1,n,md);
				rec rec2=find(1,md+1,n,n);
				printf("! %d %d %d %d %d %d %d %d\n",rec1.w1.w1,rec1.w1.w2,rec1.w2.w1,rec1.w2.w2,rec2.w1.w1,rec2.w1.w2,rec2.w2.w1,rec2.w2.w2);
				fflush(stdout);
				return 0;
			}
			if(x==2&&y==1){
				rec rec1=find(1,1,n,md-1);
				rec rec2=find(1,md,n,n);
				printf("! %d %d %d %d %d %d %d %d\n",rec1.w1.w1,rec1.w1.w2,rec1.w2.w1,rec1.w2.w2,rec2.w1.w1,rec2.w1.w2,rec2.w2.w1,rec2.w2.w2);
				fflush(stdout);
				return 0;
			}*/
			r=md-1;
		}//TLE();
	return 0;
}