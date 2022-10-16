#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define ccf f***
using namespace std;
int n,x,a[2005],b[2005],ans;
int main(){
//	freopen("1144B.in","r",stdin);
//	freopen("1144B.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x;
		if (x%2)a[++a[0]]=x;
		else b[++b[0]]=x;
	}
	sort(a+1,a+1+a[0]);
	sort(b+1,b+1+b[0]);
	for (int i=1;i<a[0]-b[0];i++)ans+=a[i];
	for (int i=1;i<b[0]-a[0];i++)ans+=b[i];
	if (abs(a[0]-b[0])<=1)ans=0;
	cout<<ans<<endl;
	return 0;
}