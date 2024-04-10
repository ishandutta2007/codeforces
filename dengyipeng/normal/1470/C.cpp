#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int n,m,i,j,k;

int ask(int x){
	printf("? %d\n",x),fflush(stdout);
	int k; scanf("%d",&k);
//	
//	static int b[maxn];
//	for(int i=1;i<=n;i++) {
//		int l=(i==1)?n:i-1,r=(i==n)?1:i+1;
//		b[i]=((l==q)?a[l]:((a[l]+1)/2))+((r==q)?0:(a[r]/2));
//	}
//	for(int i=1;i<=n;i++) a[i]=b[i];
	return k;
}

//void prepare(){
//	scanf("%d",&q);
//	for(i=1;i<=n;i++) a[i]=m;
//}

int main(){
	scanf("%d%d",&n,&m);
//	prepare();
	if (n<=400){
		for(i=1;i<=n;i++) k=ask(1);
		for(i=1;i<=n;i++){
			k=ask(i);
			if (k==m) {
				k=ask((i==1)?n:(i-1));
				if (k>=m) continue;
				k=ask((i==n)?1:(i+1));
				if (k<=m) continue;
				printf("! %d\n",i),exit(0);
			}
		}
	} else {
		int B=sqrt(n);
		for(i=1;i<=B+1;i++) {
			k=ask(1);
		}
		int id;
		for(i=1;i<=n;i+=B) {
			k=ask(i);
			if (k>m) {id=i;break;}
		}
		int l=n+id-2*B-5,r=n+id,mid; id+=n;
		while (l<=r){
			mid=(l+r)>>1;
			k=ask((mid>n)?mid-n:mid);
			if (k>m) id=mid,r=mid-1; else l=mid+1;
		}
		id--;
		printf("! %d\n",(id>n)?id-n:id);
	}
}