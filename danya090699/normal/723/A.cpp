#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
	ifstream in("input.txt");
	int a, b, c, bed=1000000000;
	cin>>a>>b>>c;
	for(int x=1; x<=100; x++)
	{
		bed=min(bed, abs(x-a)+abs(x-b)+abs(x-c));
	}
	cout<<bed;
}