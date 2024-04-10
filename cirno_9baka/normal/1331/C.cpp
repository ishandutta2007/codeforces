#include<bits/stdc++.h>
using namespace std;
const int N=500005,E=262144;
const int M=998244353;
int n,i,a[15],b[15],s;
char c;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=0;i<6;++i)
		a[i]=(n>>i)&1;
	reverse(a,a+6);
	//053241
	b[0]=a[0];
	b[4]=a[4];
	b[5]=a[1];
	b[3]=a[2];
	b[2]=a[3];
	b[1]=a[5];
	for(i=0;i<6;++i)
		s=(s<<1)|b[i];
	cout<<s;
}