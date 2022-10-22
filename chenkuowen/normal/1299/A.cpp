#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e5;
int a[MAX_N];
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=30;i>=0;--i){
		int cnt=0;
		for(int j=1;j<=n;++j)
			if(a[j]&(1<<i))
				++cnt;
		if(cnt==1){
			for(int j=1;j<=n;++j)
				if(a[j]&(1<<i)){
					swap(a[j],a[1]);
					break;
				}
			break;
		}
	}
	for(int i=1;i<=n;++i) printf("%d ",a[i]);
	int key=a[1];
	for(int i=2;i<=n;++i)
		key=(key|a[i])-a[i];
//	printf("(%d)",key);
	return 0;
}