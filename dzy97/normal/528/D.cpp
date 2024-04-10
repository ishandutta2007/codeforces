#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define N 524300
int n, m, K;
char S[N], T[N];

struct cpx{
	double a,b;
	cpx operator + (const cpx&o)const{	return (cpx){a+o.a,b+o.b};}
	cpx operator - (const cpx&o)const{	return (cpx){a-o.a,b-o.b};}
	cpx operator * (const cpx&o)const{	return (cpx){a*o.a-b*o.b,b*o.a+a*o.b};}
}c[N],d[N];
int f[N], len=0;
const double pi = 3.1415926535897932384626;

void fft(cpx *A,int n,int fl=1){
	for(int i=n>>1,j=1;j<n;j++){
	        if(i<j)  swap(A[i],A[j]);
	        int k;
	        for(k=n>>1;i&k;i^=k,k>>=1);i^=k;
	}
	for(int m=2;m<=n;m<<=1){
		cpx w=(cpx){cos(fl*2*pi/(double)m),sin(fl*2*pi/(double)m)};
		for(int k=0;k<n;k+=m){
			cpx cur=(cpx){1,0};
			for(int j=k;j<k+(m>>1);j++,cur=cur*w){
				cpx t=cur*A[j+(m>>1)],u=A[j];
				A[j]=u+t;
				A[j+(m>>1)]=u-t;
			}
		}
	}
}
char C[] = {'A', 'T', 'C', 'G'};
int cov[200010 << 4], ans[N];
#define ls (x << 1)
#define rs (x << 1 | 1)

void cover(int ql, int qr, int l, int r, int x){
	if(ql > qr) return;
	if(ql <= l && r <= qr){
		cov[x] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	if(ql <= mid) cover(ql, qr, l, mid, ls);
	if(mid < qr)  cover(ql, qr, mid + 1, r, rs);
}

void build(int l, int r, int x){
	if(l == r){
		if(cov[x]) c[l - 1].a = 1;
		return;
	}
	int mid = (l + r) >> 1;
	cov[ls] |= cov[x];
	cov[rs] |= cov[x];
	build(l, mid, ls);
	build(mid + 1, r, rs);
}
		
void work(int o){
	memset(c, 0, sizeof(c));
	memset(d, 0, sizeof(d));
	memset(cov, 0, sizeof(cov));
	
	for(int i = 1;i <= n;i ++){
		if(S[i] == C[o]){
			cover(max(1, i - K), i, 1, n, 1);
			cover(i, min(n, i + K), 1, n, 1);
		}
	}
	build(1, n, 1);
//	for(int i = 0;i < n;i ++) cout << c[i].a <<" ";cout << endl;
	for(int i = 1;i <= m;i ++){
		if(T[i] == C[o]){
			d[m - i].a = 1;
		}
	}
	fft(c, 1<<len, 1);
	fft(d, 1<<len, 1);
	for(int i = 0;i < (1 << len);i ++) c[i] = c[i] * d[i];
	fft(c, 1 << len, -1);
	for(int i = 0;i < (1 << len);i ++) f[i] = (int)round(c[i].a / (double)(1 << len));
//	for(int i = 0;i < m;i ++) cout << d[i].a <<" ";cout << endl;
	for(int i = 0;i < n;i ++)  ans[i + 1] += f[m - 1 + i];
}
int main(){
	scanf("%d%d%d", &n, &m, &K);
	scanf("%s", S + 1);
	scanf("%s", T + 1);
	while((1<<len) < (n + m + 2)) len++;
	for(int i = 0;i < 4;i ++) work(i);
	int ret = 0;
	for(int i = 1;i <= n;i ++) ret += (ans[i] == m);
	cout << ret << endl;
	return 0;
}