#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
#define N 200002
int ct[N],mx1[N],mx2[N],a[N];
bool b1[N],b2[N];
inline void Solve(){
	int n;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		ct[i]=mx1[i]=mx2[i]=0;
		b1[i]=b2[i]=false;
		scanf("%d",a+i);
	}
	for(R i=1;i<=n;i++){
		if(b1[i-1]==true||ct[a[i]]!=0){
			b1[i]=true;
		}
		ct[a[i]]++;
		mx1[i]=mx1[i-1];
		if(mx1[i]<a[i]){
			mx1[i]=a[i];
		}
	}
	for(R i=1;i<=n;i++){
		ct[i]=0;
	}
	b2[n+1]=false;
	mx2[n+1]=0;
	for(R i=n;i!=0;i--){
		if(b2[i+1]==true||ct[a[i]]!=0){
			b2[i]=true;
		}
		ct[a[i]]++;
		mx2[i]=mx2[i+1];
		if(mx2[i]<a[i]){
			mx2[i]=a[i];
		}
	}
	vector<int>A;
	for(int i=1;i!=n;i++){
		if(mx1[i]==i&&b1[i]==false&&b2[i+1]==false&&mx2[i+1]==n-i){
			A.push_back(i);
		}
	}
	printf("%d\n",A.size());
	for(R i=0;i!=A.size();i++){
		printf("%d %d\n",A[i],n-A[i]);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}