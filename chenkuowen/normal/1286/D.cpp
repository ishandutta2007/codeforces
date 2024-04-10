#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e5,MOD=998244353;
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		n&1?ret=1ll*ret*x%MOD:0;
	return ret;
}
struct Matrix{
	int a[2][2];
	int* operator[](int x){ return a[x]; }
	Matrix operator*(Matrix b){
		Matrix c;
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j){
				c[i][j]=0;
				for(int k=0;k<2;++k)
					c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%MOD;
			}
		return c;
	}
};
struct SEG{
	Matrix t[MAX_N<<2];
	void build(Matrix* s,int p,int l,int r){
		if(l==r){
			t[p]=s[l];
			return;
		}
		int m=l+r>>1;
		build(s,p+p,l,m);
		build(s,p+p+1,m+1,r);
		t[p]=t[p+p]*t[p+p+1];
	}
	void change(int p,int l,int r,int x,Matrix k){
		if(l==r){
			t[p]=k;
			return;
		}
		int m=l+r>>1;
		if(x<=m) change(p+p,l,m,x,k);
		else change(p+p+1,m+1,r,x,k);
		t[p]=t[p+p]*t[p+p+1];
	}
	Matrix query(){ 
		return t[1]; 
	}
}seg;
struct Frac{ 
	int x,y; 
	bool operator<(Frac b){
		if((y>0)^(b.y>0))  return 1ll*x*b.y<1ll*y*b.x;
		else return 1ll*x*b.y>1ll*y*b.x;
	}
};
struct Key{
	int pos,x,y;
	Frac key;
	bool operator<(Key b){
		return key<b.key;
	}
};
vector<Key> s;
int a[MAX_N],b[MAX_N],p[MAX_N],p1[MAX_N];
Matrix t[MAX_N];
void gets(int n){
	puts("");
	for(int i=1;i<=n;++i) printf("|%d %d|",t[i][0][0],t[i][0][1]); puts("");
	for(int i=1;i<=n;++i) printf("|%d %d|",t[i][1][0],t[i][1][1]); puts("");
	Matrix s=t[1];
	printf("(%d %d)",s[0][0],s[0][1]);
	for(int i=2;i<=n;++i){
		s=s*t[i];
		printf("(%d %d)",s[0][0],s[0][1]);
	}
	puts("");
}
int main(){
	int n; scanf("%d",&n);
	int inv100=fpow(100,MOD-2);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&b[i],&a[i],&p[i]);
		p[i]=1ll*p[i]*inv100%MOD;
		p1[i]=(1+MOD-p[i])%MOD;
		t[i]=(Matrix){{{0,0},{0,0}}};
	}
	t[1]=(Matrix){{{p[1],p1[1]},{0,0}}};
	for(int i=2;i<=n;++i){
		if(a[i-1]-a[i]>0)
			s.push_back((Key){i,0,0,(Frac){b[i]-b[i-1],a[i-1]-a[i]}});
		else{
//			printf("{%d %d %d}",i,0,0);
			t[i][0][0]=p[i];
		}
		if(a[i-1]+a[i]>0)
			s.push_back((Key){i,0,1,(Frac){b[i]-b[i-1],a[i-1]+a[i]}});
		else{
//			printf("{%d %d %d}",i,0,1);
			t[i][0][1]=p1[i];
		}
		if(-a[i-1]-a[i]>0)
			s.push_back((Key){i,1,0,(Frac){b[i]-b[i-1],-a[i-1]-a[i]}});
		else{
//			printf("{%d %d %d}",i,1,0);
			t[i][1][0]=p[i];
		}
		if(a[i]-a[i-1]>0)
			s.push_back((Key){i,1,1,(Frac){b[i]-b[i-1],a[i]-a[i-1]}});
		else{
//			printf("{%d %d %d}",i,1,1);
			t[i][1][1]=p1[i];
		}
	}
	seg.build(t,1,1,n);
	sort(s.begin(),s.end());
//	reverse(s.begin(),s.end());
	vector<int> ans; ans.resize(s.size());
//	for(int i=0;i<s.size();++i)
//		printf("(%d %d %d)",s[i].pos,s[i].x,s[i].y);
//	puts("");
//	exit(0);
//	gets(n);
	int ret=0,last=(seg.query()[0][0]+seg.query()[0][1])%MOD;
	for(int i=0;i<s.size();++i){
//		printf("(%d %d %d %d %d)",s[i].pos,s[i].x
//			,s[i].y,s[i].key.x,s[i].key.y);
		t[s[i].pos][s[i].x][s[i].y]=(s[i].y?p1[s[i].pos]:p[s[i].pos]);
		seg.change(1,1,n,s[i].pos,t[s[i].pos]);
		ans[i]=(seg.query()[0][0]+seg.query()[0][1])%MOD;
//		gets(n);
		ret=(ret+1ll*(ans[i]+MOD-(i==0?last:ans[i-1]))
			*s[i].key.x%MOD*fpow(s[i].key.y,MOD-2))%MOD;
	}
	printf("%d\n",(ret+MOD)%MOD);
	return 0;
}