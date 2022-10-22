// Problem: CF685D Kay and Eternity
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF685D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
template<class T>
inline void read(T &x){
	x=0;char c=getchar();bool flag=false;
	for(;!isdigit(c);c=getchar())flag|=c=='-';
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	if(flag)x=-x;
}
template<class T>
inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int N=2e5+10;
int n,k;
struct node{
	int x,l,r,t;
	bool operator<(const node&rhs)const{
		return x<rhs.x;
	}
}e[N];
vector<int>vec;
int c[N],ans[N];
int lx;
void upd(int p,int v){
	int len=vec[p+1]-vec[p];
	ans[c[p]]-=len*lx;
	c[p]+=v;
	ans[c[p]]+=len*lx;
}
signed main(){
	read(n);read(k);
	for(int i=1;i<=n;i++){
		int x,y;read(x);read(y);
		e[2*i-1]={x,y,y+k-1,1};
		e[2*i]={x+k,y,y+k-1,-1};
		vec.push_back(y);
		vec.push_back(y+k);
	}
	sort(e+1,e+1+2*n);
	sort(vec.begin(),vec.end());
	vec.resize(unique(vec.begin(),vec.end())-vec.begin());
	for(int i=1;i<=2*n;i++){
		int j=i;
		while(j+1<=2*n&&e[j+1].x==e[i].x)j++;
		lx=e[2*n].x-e[i].x;
		for(int k=i;k<=j;k++){
			int l=lower_bound(vec.begin(),vec.end(),e[k].l)-vec.begin();
			int r=lower_bound(vec.begin(),vec.end(),e[k].r+1)-vec.begin();
			for(int w=l;w<r;w++)
				upd(w,e[k].t);
		}i=j;
	}
	for(int i=1;i<=n;i++)
		write(ans[i]),putchar(' ');
}