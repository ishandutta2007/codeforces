#include<iostream>
#include<string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a, b;	cin >> a >> b;

	int i = 0;
	while (i < (int)a.size() - 1 && a[i] == '0')	i++;
	{
		string c = "";
		for (int j = i; j < a.size(); j++)
			c += a[j];
		a = c;
	}

	i = 0;
	while (i < (int)b.size() - 1 && b[i] == '0')	i++;
	{
		string c = "";
		for (int j = i; j < b.size(); j++)
			c += b[j];
		b = c;
	}

	if (a.size() != b.size()){
		if (a.size() > b.size())
			cout << ">\n";
		else
			cout << "<\n";
		return	0;
	}
	if (a == b){
		cout << "=\n";
		return	0;
	}
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i]){
			if (a[i] > b[i])
				cout << ">\n";
			else
				cout << "<\n";
			return	0;
		}
	return	0;
}