#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int t=n;
	while (t>=10)t=t/10;
	t++;
	while (t<=n)t*=10;
	cout<<t-n<<endl;
}