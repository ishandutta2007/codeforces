#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500004];
int b[22];
int p[22],l[500004];
int ans[500004];
vector<int>qr[500004];
void upd(int X,int w){
	for(int i=20;~i;i--)if((1<<i)&X){
		if(!b[i]){
			b[i]=X,p[i]=w;
			break;
		}
		if(w>p[i])swap(b[i],X),swap(p[i],w);
		X^=b[i];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int r;scanf("%d%d",&l[i],&r);
		qr[r].push_back(i);
	}
	for(int i=1;i<=n;i++){
		upd(a[i],i);
		for(auto I:qr[i]){
			int w=l[I],X=0;
			for(int i=20;~i;i--)if(w<=p[i]&&(X^b[i])>X)X^=b[i];
			ans[I]=X;
		}
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
}