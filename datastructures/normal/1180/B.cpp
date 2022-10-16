#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,a[100005],x,y;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==0)a[i]=-a[i]-1;
		if (a[i]<0)x++;
		if (a[i]>0)y++;
	}
	for (int i=1;i<=n;i++){
		if (a[i]>0)a[i]=-a[i]-1;
	}
	if (n%2==1){
		int tmp=2e9;
		for (int i=1;i<=n;i++)
			tmp=min(tmp,a[i]);
		for (int i=1;i<=n;i++){
			if (a[i]==tmp)tmp=2e9,a[i]=-a[i]-1;
		}
	}
	for (int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
	return 0;
}