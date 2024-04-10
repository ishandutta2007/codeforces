#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n,m;bool fl=false;
		scanf("%d%d",&n,&m);
		for(int i=1,a,b,c,d;i<=n;i++){
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(b==c)fl=true;
		}
		if((!(m&1))&&fl)puts("YES");
		else puts("NO");
	}
	return 0;
}