#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX_N = 3006;

int a[MAX_N];

int main () {
	int n,k;
	scanf("%d %d",&n,&k);
	for (int i=1;n>=i;i++) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int ans=0;
	for (int i=1;k>=i;i++) ans+=a[i];
	cout<<ans<<endl;
}