#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e6+10,P=1e9+7;
const int z[5][4]={{1,0},{0,1}};




int n,m;
struct Node{
	int x,id;
	bool operator < (const Node __) const{
		return x>__.x;
	}
}A[N];
int B[N];



int main(){
	n=rd();
	rep(i,1,n) {
		A[i]=(Node){rd(),i};
		B[i]=i*2-1;
	}
	sort(A+1,A+n+1);
	rep(i,1,n) B[i]=A[i].id*2-1;
	rep(i,2,n) printf("%d %d\n",A[i].id*2-1,A[i-1].id*2-1);
	int cnt=n;
	rep(i,1,n) {
		printf("%d %d\n",A[i].id*2,B[i+A[i].x-1]);
		if(i+A[i].x>cnt) cnt++,B[i+A[i].x]=A[i].id*2;
	}
}