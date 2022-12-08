#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n;
int a[maxn],s[maxn],pos[maxn];
char t[maxn];
int main(){
	//freopen(".in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]),pos[a[i]]=i; scanf("%s",t+1);
	for (int i=1;i<n;++i){
		s[i]=s[i-1]; if (t[i]=='1') ++s[i]; 
	}
	for (int i=1;i<=n;++i){
		int l=i,r=a[i];
		if (l>r) swap(l,r);
		//printf("s[%d]=%d s[%d]=%d\n",l,s[l],r,s[r]);
		if (s[r-1]-s[l-1]!=(r-l)){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}