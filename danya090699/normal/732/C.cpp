#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
main()
{
	int a[3], an=0;
	cin>>a[0]>>a[1]>>a[2];
	sort(a, a+3);
	if(a[0]<a[2]-1) an+=a[2]-1-a[0];
	if(a[1]<a[2]-1) an+=a[2]-1-a[1];
	cout<<an;
}