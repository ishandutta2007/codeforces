#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
int n,k,e[1010][1010],c;
void slv(int bg,int n,int col){
	if(n<=k){for(int i=1;i<n;++i) for(int j=n;j>i;--j) e[i+bg][j+bg]=col;return;}
	vector<int> l(k),r(k);
	for(int i=0;i<k;++i) r[i]=n/k+(i<n%k);
	for(int i=l[0]=1;i<k;++i) l[i]=r[i-1]+1,r[i]+=r[i-1];
	for(int i=0;i<k;++i) for(int j=i+1;j<k;++j)
		for(int $=l[i];$<=r[i];++$) for(int _=l[j];_<=r[j];++_) e[$+bg][_+bg]=col;
	for(int i=0;i<k;++i) slv(bg+l[i]-1,r[i]-l[i]+1,col+1);
}
int main(){
	scanf("%d%d",&n,&k);
	slv(0,n,1);
	for(int i=1;i<n;++i) for(int j=n;j>i;--j) c=max(c,e[i][j]);
	printf("%d\n",c);
	for(int i=1;i<n;++i) for(int j=i+1;j<=n;++j) printf("%d ",e[i][j]); 
	return 0;
}