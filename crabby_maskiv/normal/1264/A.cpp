#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=400005;
int n,m;
int a[N];
int main(){
	int i,j;
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		int pg,ps=0,pb=n/2;
		while(pb>1&&a[pb]==a[pb+1]) pb--;
		if(pb==1){
			printf("0 0 0\n");
			continue;
		}
		bool flag=0;
		for(pg=1;pg*3<pb;pg++){
			if(a[pg]==a[pg+1]) continue;
			ps=max(ps,pg+1);
			while(ps<pb&&(ps-pg<=pg||a[ps]==a[ps+1])) ps++;
			if(pb-ps<=pg||ps-pg<=pg) continue;
			flag=1;
			printf("%d %d %d\n",pg,ps-pg,pb-ps);
			break;
		}
		if(!flag) printf("0 0 0\n");
	}
	return 0;
}