#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin>>n>>k;
	long long t=0;
	for (int i=0; i<n; i++){
		int w;
		cin>>w;
		t+=((w-1)/k)+1;
	}
	cout<<((t-1)/2+1);
}