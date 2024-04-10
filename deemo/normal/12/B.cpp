#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int a[14];

int main(){
	int x;	cin >> x;
	int cur = 0;
	while (x){
		a[cur++] = x%10;
		x /= 10;
	}
	sort(a, a + cur);
	int z = 0, ind = 0;
	for (int i = 0; i < cur; i++)	
		if (a[i]){
			z = a[i];
			ind = i;
			break;
		}
	for (int i = 0; i < cur; i++)
		if (i != ind)	z = z * 10 + a[i];
	string y;	cin >> y;
	string temp = "";
	if (z == 0)	temp = "0";
	while (z){
		temp = char((z % 10) + '0') + temp;
		z /= 10;
	}
	if (temp == y)
		cout << "OK\n";
	else
		cout << "WRONG_ANSWER\n";
	return	0;
}