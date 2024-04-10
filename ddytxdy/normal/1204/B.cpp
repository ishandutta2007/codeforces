#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1010;
char c[N];int n,l,r,a[N];bool flag;LL sum;
int main(){
	scanf("%d%d%d",&n,&l,&r);
	a[1]=1;
	for(int i=2;i<=n-l+1;i++)a[i]=1;sum=n-l+1;
	for(int i=n-l+2;i<=n;i++)a[i]=a[i-1]*2,sum+=a[i];
	cout<<sum<<" ";sum=1;
	for(int i=2;i<=r;i++){
		a[i]=a[i-1]*2;sum+=a[i];
	}
	for(int i=r+1;i<=n;i++)sum+=a[r];
	cout<<sum<<" ";
}