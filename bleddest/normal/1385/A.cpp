#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		vector<int> aux;
		aux.push_back(x);
		aux.push_back(y);
		aux.push_back(z);
		sort(aux.begin(), aux.end());
		x = aux[0];
		y = aux[1];
		z = aux[2];
		if(y == z)
		{
			cout << "YES" << endl;
			cout << x << " " << x << " " << z << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}