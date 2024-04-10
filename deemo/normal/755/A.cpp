#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e6;

bool pr[MAXN];

int main(){
	pr[0] = pr[1] = 1;
	for (int i = 2; i < MAXN; i++)
		if (!pr[i])
			for (int j = i + i; j < MAXN; j += i)
				pr[j] = 1;

	int n;	cin >> n;
	for (int i = 1; ; i++)
		if (pr[n*i+1]){
			cout << i << endl;
			return 0;
		}
	return 0;
}