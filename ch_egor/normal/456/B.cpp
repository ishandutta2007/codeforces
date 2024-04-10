#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;


int main()
{
	pair<int, int> arr[100005];
	string st;
	int number;

	cin >> st;

	if (st.size() >= 2)
		number = st[st.size() - 2]*10 + st[st.size() - 1] - 48 * 2;
	else
		number = st[st.size() - 1] - 48;
	
	number %= 4;

	int answer = ceil(1 + floor(pow(2, number)) + floor(pow(3, number)) + floor(pow(4, number)));
	answer %= 5;
	cout << answer;

	cin.get();
	cin.get();

	return 0;
}