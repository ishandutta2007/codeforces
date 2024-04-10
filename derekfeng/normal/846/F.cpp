#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
int n,a[1000004],pre[1000004];
ll ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),ans+=2ll*(i-pre[a[i]])*(n-i+1),pre[a[i]]=i;
	printf("%.6lf",(db)(ans-n)/(db)n/(db)n);
}