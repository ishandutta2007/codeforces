#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
long long a[3],b[3],x,f=10000000000;
int lst,i;
int main()
{
	cin>>a[0]>>a[1]>>a[2];lst=-1;
	cout<<"First\n"<<flush;
	cout<<f<<endl<<flush;
	cin>>x;x--;
	a[x]+=f;
	memcpy(b,a,sizeof(a));
	sort(b,b+3);
	cout<<(b[2]*2-b[0]-b[1])<<endl<<flush;
	cin>>x;x--;
	a[x]+=(b[2]*2-b[0]-b[1]);
	memcpy(b,a,sizeof(a));
	sort(b,b+3);
	cout<<b[2]-b[1]<<endl<<flush;
	cin>>x;
	return 0;
}