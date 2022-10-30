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

const int N=1e5+5;

int n,k,w,c[N];
int lst[N],a[N],cnt;
bool ck[N];
int ans[N][2];
int lft[N],id[N];

int main() {
	n=read(),k=read(),w=n/(k-1)+(!!(n%(k-1)));
	for(int i=1 ; i<=n*k ; ++i) {
		a[i]=read();
		if(lst[a[i]]) lft[i]=lst[a[i]],id[i]=a[i];
		lst[a[i]]=i;
	}
	for(int i=1 ; i<=n*k ; ++i) {
		if(!ck[id[i]]&&lft[i]) {
			int mx=0;
			for(int j=lft[i] ; j<=i ; ++j) mx=max(mx,c[j]);
			if(mx==w) continue ;
			ck[id[i]]=1,ans[id[i]][0]=lft[i],ans[id[i]][1]=i;
			for(int j=lft[i] ; j<=i ; ++j) ++c[j];
		}
	}
	for(int i=1 ; i<=n ; ++i)
		printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}