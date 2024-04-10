#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define vit vector<int>::iterator
#define sit set<int>::iterator
#define pb push_back
#define ll long long
using namespace std;
const int N=1e6+6; 
int n,v1[N][2],v2[N][2],a[1000][1000];
void go(int x,int y,int z){
	printf("%d %d %d\n",x,y,z);
	fflush(stdout);
}
int main(){
	int m=0,k=0; scanf("%d",&n);
	rep(i,1,n) rep(j,1,n) 
		if (i+j&1) v1[++m][0]=i,v1[m][1]=j;
		else v2[++k][0]=i,v2[k][1]=j;
	int c1=0,c2=0;
	rep(t,1,n*n){
		int op; scanf("%d",&op);
		if (op!=1){
			if (c1<m) go(1,v1[c1+1][0],v1[c1+1][1]),++c1;
			else go(op^1,v2[c2+1][0],v2[c2+1][1]),++c2;
		}
		else{
			if (c2<k) go(2,v2[c2+1][0],v2[c2+1][1]),++c2;
			else go(3,v1[c1+1][0],v1[c1+1][1]),++c1;
		}
	}
	return 0;
}