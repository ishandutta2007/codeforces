#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
typedef double db;
typedef pair<db,int> pdi;
#define fi first
#define se second
const db pi=acos(-1);
struct comp{
    db x,y;
    comp(db x=0,db y=0):x(x),y(y){}
    comp operator +(const comp &o){return comp(x+o.x,y+o.y);}
    comp operator -(const comp &o){return comp(x-o.x,y-o.y);}
    comp operator *(const comp &o){return comp(x*o.x-y*o.y,x*o.y+y*o.x);}    
    comp operator *(const db &o){return comp(x*o,y*o);}
    comp operator /(const db &o){return comp(x/o,y/o);}
};
int N,lg;
int rev[65540];
db COS[23],SIN[23];
void fft(comp *A,int t){
    for(int i=0;i<N;i++)if(rev[i]>i)swap(A[i],A[rev[i]]);
    for (int i=0;i<lg;i++){
        int mid=(1<<i);
        comp Wn{COS[i],t*SIN[i]};
        for(int j=0;j<N;j+=(mid<<1)){
            comp w{1,0};
            for(int k=0;k<mid;k++,w=w*Wn){
                comp x=A[j+k],y=w*A[j+mid+k];
                A[j+k]=x+y,A[j+mid+k]=x-y;
            }
        }
    }
    if(t<0)for(int i=0;i<N;i++)A[i]=A[i]/N;
}
comp A[65540],B[65540];
vector<db>merge(const vector<db> &a,const vector<db> &b){
    int n=a.size()-1,m=b.size()-1;
    if(n+m<=100){
    	vector<db>res(n+m+1,0);
    	for(int i=0;i<=n;i++)
    		for(int j=0;j<=m;j++)
    			res[i+j]+=a[i]*b[j];
    	return res;
	}
    N=1,lg=0;while(N<=n+m)N<<=1,lg++;
    for(int i=0;i<N;i++)A[i]=comp{0,0},B[i]=comp{0,0};
    for(int i=0;i<=n;i++)A[i].x=a[i];
    for(int i=0;i<=m;i++)B[i].x=b[i];
    for(int i=1;i<N;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
    for(int i=0,mid=1;i<=lg;i++,mid<<=1)COS[i]=cos(pi/mid),SIN[i]=sin(pi/mid);
    fft(A,1),fft(B,1);
    for(int i=0;i<N;i++)A[i]=A[i]*B[i];
    fft(A,-1);
    vector<db>res;
    for(int i=0;i<=n+m;i++)res.push_back(A[i].x);
    return res;
}
int n,m,T,C,u[105],v[105],w[105];
db pro[105][20004];
db dp[55];
void task1(){
	for(int i=1;i<n;i++)dp[i]=1e18;
	for(int t=1;t<=n;t++)
		for(int i=1;i<=m;i++)
			dp[u[i]]=min(dp[v[i]]+w[i],dp[u[i]]);
}
db f[40004][105],g[40004][55];
void solve(int l,int r){
	if(l==r){
		for(int i=1;i<=n;i++)g[l][i]=1e18;
		for(int i=1;i<=m;i++)g[l][u[i]]=min(g[l][u[i]],f[l][i]+w[i]);
		g[l][n]=0;
		return;
	}
	int md=(l+r)>>1;
	if(md>T)solve(l,md);
	for(int t=1;t<=m;t++){
		vector<db>A,B;
		for(int i=l;i<=md;i++)A.push_back(g[i][v[t]]);
		int len=r-l+1;
		for(int i=1;i<=len&&i<=T;i++)B.push_back(pro[t][i]);
		vector<db>C=merge(A,B);
		for(int i=md+1;i<=r;i++)f[i][t]+=C[i-l-1];
	}
	solve(md+1,r);
}
void task2(){
	for(int i=0;i<=T;i++)
		for(int j=1;j<=n;j++){
			g[i][j]=dp[j]+C;
			if(i==T&&j==n)g[i][j]=0;
		}
	solve(0,T+T);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&T,&C);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		for(int j=1;j<=T;j++)scanf("%lf",&pro[i][j]),pro[i][j]/=100000;
	}
	task1();
	task2();
	printf("%.8lf",g[T+T][1]);
}