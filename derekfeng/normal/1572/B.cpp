#include<bits/stdc++.h>
using namespace std;
int t,n,a[200004],d[200004];
void sol(){
	vector<int>r;
	scanf("%d",&n);
	int s=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),d[i]=d[i-1]^a[i];
	if(d[n]){
		puts("NO");
		return;
	}
	if(n&1){
		for(int i=1;i<=n-2;i+=2)r.push_back(i);
		for(int i=n-4;i>=1;i-=2)r.push_back(i);
	}else{
		bool ok=0;
		for(int i=1;i<=n;i+=2)if(d[i]==0){
			for(int j=1;j<=i-2;j+=2)r.push_back(j);
			for(int j=i-4;j>=1;j-=2)r.push_back(j);
			int m=n-i;
			for(int j=1;j<=m-2;j+=2)r.push_back(j+i);
			for(int j=m-4;j>=1;j-=2)r.push_back(j+i);
			ok=1;break;
		}
		if(!ok){
			puts("NO");
			return;
		}
	}
	puts("YES");
	printf("%d\n",r.size());
	for(auto x:r)printf("%d ",x);puts("");
}
int main(){for(scanf("%d",&t);t--;sol());}