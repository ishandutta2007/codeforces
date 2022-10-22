// Problem: CF1270I Xor on Figures
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1270I
// Memory Limit: 250 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=512;
int n,k,t;
struct matrix{
	long long a[N][N];
	void clear(){memset(a,0,sizeof a);}
	long long  *operator[](int x){return a[x];}
	vector<pair<int,int>> work(){
		vector<pair<int,int>>has;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(a[i][j])has.push_back({i,j});
		return has;
	}
	void print(){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				write(a[i][j]),putchar(" \n"[j+1==n]);
		
	}
}A,res,f,tmp;
void mul(matrix&res,matrix&a,matrix&b){
	auto has=b.work();
	//printf("%d\n",has.size());
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)
		for(auto X:has){
			int x=X.first,y=X.second;
			res[(i+x)%n][(j+y)%n]^=a[i][j]*b[x][y];
		}
}
signed main(){
	read(k);
	n=1<<k;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			read(A[i][j]);
	read(t);
	//t=9;
	for(int i=0,x,y;i<t;i++)
		read(x,y),
		f[x%n][y%n]=1;
	//f.print();
	mul(res,A,f);
	for(int i=1;i<k;i++){
		//printf("%d\n",i);
		tmp=f;f.clear();
		mul(f,tmp,tmp);
		//f.print();
		tmp=res;res.clear();
		mul(res,tmp,f);
	}
	int cnt=0;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)
		cnt+=res[i][j]!=0;
	write(cnt);
}