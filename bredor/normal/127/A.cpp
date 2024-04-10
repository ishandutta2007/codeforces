//  228

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, k,x1,x2,y1,y2;
	double sum = 0.0,p;
	cin >> n >> k;
	cin >> x1 >> y1;
	for(int i =1; i < n; i++)
	{
		cin >> x2 >> y2;
		p = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		x1 = x2;
		y1 = y2;
		sum += p;

	}
	sum *= k;
	sum /= 50;
	cout<< fixed << setprecision(9) << sum << "\n";

}