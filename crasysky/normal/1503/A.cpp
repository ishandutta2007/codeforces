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
char s[N]; int a[N],b[N],sum[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d%s",&n,s);
		per(i,n-1,0) sum[i]=(i==n-1?0:sum[i+1])+(s[i]=='0');
		int s1=0,s2=0,c1=0,c2=0; bool t=false;
		rep(i,0,n-1){
			if (s[i]=='1'){
				if (max(c1+1+sum[i]/2,c2+1+(sum[i]+1)/2)<=n/2)
					a[i]=b[i]=1,++s1,++s2,++c1,++c2;
				else a[i]=b[i]=0,--s1,--s2;
			}
			else{
				if (s1<=s2) a[i]=1,b[i]=0,++s1,--s2,++c1;
				else a[i]=0,b[i]=1,--s1,++s2,++c2;
			}
			if (s1<0||s2<0){ t=true; break; }
		}
		if (s1||s2||t) puts("NO");
		else{
			puts("YES");
			rep(i,0,n-1) putchar(a[i]==1?'(':')');
			putchar('\n');
			rep(i,0,n-1) putchar(b[i]==1?'(':')');
			putchar('\n');
		}
	}
}