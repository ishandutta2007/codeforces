#include<bits/stdc++.h>
using namespace std;

int T,N,p[100005],c[100005];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=1;i<=N;i++) scanf("%d%d",&p[i],&c[i]);
		bool flg=1;
		for(int i=1;i<=N;i++)
			if(p[i]<c[i]||p[i]-p[i-1]<c[i]-c[i-1]||p[i]<p[i-1]||c[i]<c[i-1]) flg=0;
		if(flg) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}