#include <iostream>
#include <cstdio>
using namespace std;
int v1[105],v2[105],val[105][105],x[10005],y[10005],n,k,p,q,v;
void work(int p,int w,int v,int *a){
	a[p+(1<<w)]=v;
	if (w==0)return;
	work(p,w-1,v/4,a);
	work(p+(1<<w),w-1,v/4,a);
	return;
}
int main(){
	work(0,4,512,v1);
	work(0,4,256,v2);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			if (i>1)val[i][j]=val[i-1][j]^v1[i-1];
			if (j>1)val[i][j]=val[i][j-1]^v2[j-1];
			x[val[i][j]]=i,y[val[i][j]]=j;
		}
	for (int i=1;i<=n;i++){
		for (int j=1;j<n;j++)cout<<v2[j]<<' ';
		cout<<endl;
	}
	for (int i=1;i<n;i++){
		for (int j=1;j<=n;j++)cout<<v1[i]<<' ';
		cout<<endl;
	}
	p=q=1;
	while(k--){
		cin>>v;
		int _p=p,_q=q;
		p=x[val[p][q]^v],q=y[val[p][q]^v];
		cout<<p<<' '<<q<<endl;
	}
	return 0;
}