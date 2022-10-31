#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
using namespace std;
const int N=1e6+6;
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,k; scanf("%d%d",&n,&k);
		static char s[N]; scanf("%s",s);
		static int v[N]; rep(i,0,k-1) v[i]=0;
		bool no=false;
		rep(i,0,n-1)
			if (s[i]!='?'){
				int t=s[i]=='1'?1:-1;
				if (v[i%k]&&v[i%k]!=t) no=true;
				else v[i%k]=t;
			}
		int c=0,t=0; 
		rep(i,0,k-1) c+=v[i],t+=!v[i];
		if (no||c+t<0||c-t>0) puts("NO");
		else puts("YES");
	}
	return 0;
}