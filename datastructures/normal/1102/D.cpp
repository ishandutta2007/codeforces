#include <iostream>
#include <cstdio>
using namespace std;
string x;
int n,a[300005],book[3];
int main(){
//	freopen("1102D.in","r",stdin);
//	freopen("1102D.out","w",stdout);
	cin>>n>>x;
	for (int i=1;i<=x.size();i++)a[i]=x[i-1]-'0',book[a[i]]++;
	for (int i=n;i>=1&&book[2]<n/3;i--)
		if (a[i]!=2&&book[a[i]]>n/3)book[2]++,book[a[i]]--,a[i]=2;
	for (int i=1;i<=n&&book[0]<n/3;i++)
		if (a[i]!=0&&book[a[i]]>n/3)book[0]++,book[a[i]]--,a[i]=0;
	for (int i=1;i<=n&&book[1]<n/3;i++)
		if (a[i]==2&&book[2]>n/3)book[1]++,book[2]--,a[i]=1;
	for (int i=n;i>=1&&book[1]<n/3;i--)
		if (a[i]==0&&book[0]>n/3)book[1]++,book[0]--,a[i]=1;
	for (int i=1;i<=n;i++)printf("%d",a[i]);
	cout<<endl;
	return 0;
}