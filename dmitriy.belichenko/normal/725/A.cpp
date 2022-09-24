#include<string>
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k = 0;
	int u = 0;
	while (s[u] == '<' && u <= n - 1)
	{
		u++;
		k++;
	}
	u = n - 1;
	while (u >=0  && s[u] == '>')
	{
		u--;
		k++;
	}
	cout << k;

}