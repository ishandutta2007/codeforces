#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX_N=5+1e5;
int a[MAX_N],n,m,key=0;
bool mark[MAX_N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		a[i]%=m;
		key=__gcd(key,a[i]);
	}
	for(int i=0;i<m;++i) mark[i]=false;
	for(long long i=0;i<m;++i)
		mark[i*key%m]=true;
	int top=0;
	for(int i=0;i<m;++i)
		if(mark[i]) ++top;
	printf("%d\n",top);
	for(int i=0;i<m;++i)
		if(mark[i]) printf("%d ",i);
	return 0;
}