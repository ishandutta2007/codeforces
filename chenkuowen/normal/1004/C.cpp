#include<cstdio>
#include<cstring>
const int MAX_N=5+1e5;
int a[MAX_N];
bool mark[MAX_N],b[MAX_N];
typedef long long ll;
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	memset(mark,0,sizeof(mark));
	memset(b,0,sizeof(b));
	for(int i=n;i>=1;--i) {
		if(!b[a[i]]) mark[i]=true;
		b[a[i]]=true;
	}
	memset(b,0,sizeof(b));
	int sum=0;
	ll ans=0;
	for(int i=1;i<=n;++i){
		if(mark[i]) ans+=sum;
		if(!b[a[i]]){
			b[a[i]]=true;
			++sum;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}