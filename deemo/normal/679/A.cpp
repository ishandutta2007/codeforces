#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool f(int x){
	for (int i = 2; i < x; i++)
		if (x % i == 0)	return false;
	return true;
}

int main(){
	int pr = -1, cnt = 0;
	for (int i = 2; i <= 50; i++)
		if (f(i)){
			cout << i << endl;
			string temp;	cin >> temp;
			if (temp == "yes"){
				cnt++;
				pr = i;
			}
		}

	if (cnt > 1){
		cout << "composite" << endl;
		return 0;
	}
	if (cnt == 0){
		cout << "prime" << endl;
		return 0;
	}

	if (pr * pr > 100){
		cout << "prime" << endl;
		return 0;
	}

	cout << pr * pr << endl;
	string temp;	cin >> temp;
	if (temp == "yes"){
		cout << "composite" << endl;
	}
	else{
		cout << "prime" << endl;
	}
	return 0;
}