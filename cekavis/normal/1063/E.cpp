#include<cstdio>
#include<algorithm>
const int N = 1005;
int n, last, a[N];
char ans[N][N];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) if(scanf("%d", a+i), a[i]!=i) last=i;
	if(last){
		char x='/', y='\\';
		for(int i=n; i; --i, std::swap(x, y)){
			int p=0;
			if(x=='/'){ for(int j=1; j<last; ++j) if(a[j]!=j){ p=j; break;} }
			else for(int j=n; j>last; --j) if(a[j]!=j){ p=j; break;}
			if(!p) break;
			ans[i][p]=ans[i][last]=ans[i][a[p]]=x;
			a[last]=a[a[p]], a[a[p]]=a[p], last=p;
		}
	}
	printf("%d\n", n-(last>0));
	for(int i=1; i<=n; ++i, puts("")) for(int j=1; j<=n; ++j) putchar(ans[i][j]?ans[i][j]:'.');
	return 0;
}