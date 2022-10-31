#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;

inline int read() {
	int res=0;char ch;
	while(ch=getchar(),ch<'0'||ch>'9');
	do {
		res=res*10+ch-'0';
	} while(ch=getchar(),ch>='0'&&ch<='9');
	return res;
}

const int N=50005;

int a[N][5],c[N],n;

inline bool cmp(int x,int y) {
	int c=0;
	for(int i=0 ; i<5 ; ++i) c+=a[x][i]<a[y][i];
	return c>=3;
}

inline bool check(int id) {
	for(int i=1 ; i<=n ; ++i)
		if(i!=id)
			if(cmp(i,id)) return 0;
	return 1;
}

int main() {
	int T=read();
	while(T--) {
		n=read();
		for(int i=1 ; i<=n ; ++i) c[i]=0;
		for(int i=1 ; i<=n ; ++i)
			for(int j=0 ; j<5 ; ++j)
				a[i][j]=read();
		int id=1;
		for(int i=2 ; i<=n ; ++i)
			if(cmp(i,id)) id=i;
		if(check(id)) printf("%d\n",id);
		else puts("-1");
	}
	return 0;
}