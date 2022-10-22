#include<cstdio>
#include<algorithm>
const int N=2e5+1;
int n,m,a,b[N],k;
inline bool Check(int g){
	int s=0;
	for(int j=1;j<N;j++)
	  s+=b[j]/g;
	return s>=m;
}
int main(){
	int l,r,md;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a),b[a]++;
	for(l=1,r=n;l<r;)md=l+r+1>>1,Check(md)?l=md:r=md-1;
	for(int j=1;j<N;j++){
	  for(int i=b[j]/l;i;i--){
		printf("%d ",j),k++;
		if(k==m)return 0;
	  }
	}
}