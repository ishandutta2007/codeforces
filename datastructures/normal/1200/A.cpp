#include <iostream>
#include <cstdio>
using namespace std;
char c;
int n;
int a[15],l,r=9;
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		l=0,r=9;
		while (a[l]==1)l++;
		while (a[r]==1)r--; 
		cin>>c;
		if (c=='L')a[l]=1;
		if (c=='R')a[r]=1;
		if (c>='0'&&c<='9')
			a[c-'0']=0;
	}
	for (int i=0;i<=9;i++)cout<<a[i];
	return 0;
}