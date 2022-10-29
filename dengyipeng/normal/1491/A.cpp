#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100005
using namespace std;

int n,q,i,j,k,a[maxn],cnt;

int main(){
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),cnt+=a[i];
	while (q--){
		int tp,x; scanf("%d%d",&tp,&x);
		if (tp==1) cnt-=a[x],a[x]^=1,cnt+=a[x]; else{
			if (cnt>=x) printf("1\n");
			else printf("0\n");
		}
	}
}