//  228

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100005;
int a[N],n;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<n;i++) {
		if((a[i+1]>a[i]&&a[i]<a[1])||(a[i+1]<a[i]&&a[i]>a[1])) {
			printf("3\n1 %d %d\n",i,i+1);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}