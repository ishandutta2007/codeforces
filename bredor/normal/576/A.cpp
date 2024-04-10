#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <bitset>
#define int228 long long
#define mp make_pair
#define pb push_back
using namespace std;

const int228 VERY_DOHERA = 1000000007;

bool prostoe(int p){
	for(int i = 2; i * i <= p; i++)
		if(p % i == 0)
			return 0;
	return 1;
}

int main(){
	int n;
	cin >> n;
	vector<int> otvet;
	for(int i = 2; i <= n; i++)
		if(prostoe(i))
			for(int j = i; j <= n; j *= i)
				otvet.pb(j);
	cout << otvet.size() << endl;
	for(int i = 0; i < otvet.size(); i++)
		cout << otvet[i] << ' ';
	return 14 / 88;
}