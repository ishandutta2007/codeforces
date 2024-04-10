#include <iostream>
using namespace std;

int main() {
	int x,y;
	cin>>x>>y;
	int k=min(x,y);
	int a=x;
	int b=0;
	cout<<k+1<<endl;
	for(int i=0;i<k+1;i++)
	{
		cout<<a<<" "<<b<<endl;
		a--;
		b++;
	}
	return 0;
}