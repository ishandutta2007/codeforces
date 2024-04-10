#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
class S
{
public:
	string s;
	bool operator < (S p)const
	{
		return (s + p.s) < (p.s + s);
	}
};
int main()
{
	int num;
	scanf("%d", &num);
	vector<S>vec;
	for (int i = 0; i < num; i++)
	{
		string s;
		cin >> s;
		S x;
		x.s = s;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < num; i++)cout << vec[i].s;
	cout << endl;
}