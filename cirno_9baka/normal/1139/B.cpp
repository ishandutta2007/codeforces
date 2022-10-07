#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int N=100005;
int n,i,a[200005],s=1<<30;
long long ans;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=n;i>=1;i--)
	{
		s=max(0,min(s-1,a[i]));
		ans+=s;
	}
	cout<<ans;
}