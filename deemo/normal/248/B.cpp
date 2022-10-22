#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n;
string s;
int a[6] = {1, 3, 2, 6, 4, 5};

bool ok(){
	long long sum = 0;
	for (int i = 0; i < n; i++)
		sum += s[i] - '0';
	if (sum % 3)	return	false;
	if (s[n - 1] != '0')	return	false;
		
	string t = s;
	reverse(t.begin(), t.end());
	sum = 0;
	for (int i = 0; i < n; i++)
		sum += (t[i] - '0') * a[i % 6];
	return	sum % 7 == 0;
}

void pl(){
	s[n - 1]++;
	for (int i = n - 1; i >= 0; i--)
		if (s[i] <= '9')
			return;
		else
			s[i] = '0', s[i - 1]++;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if (n < 3){
		cout << -1 << endl;
		return 0;
	}
	s = "1";
	for (int i = 0; i < n - 1; i++)
		s += "0";
	while (!ok())	
		pl();
	cout << s << endl;
	return 0;
}