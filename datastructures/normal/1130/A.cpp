#include <iostream>
#include <cstdio>
using namespace std;
int n,a[100005],b,c;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		if (a[i]>0)b++;
		else if (a[i]<0)c++;
	if (b*2>=n)cout<<1<<endl;
	else if (c*2>=n)cout<<-1<<endl;
	else cout<<0<<endl;
	return 0;
}