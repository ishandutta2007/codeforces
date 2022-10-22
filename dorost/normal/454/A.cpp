#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	for (int i = 0; i <= n / 2; i++){
        for (int j = 0; j < n / 2 - i; j++){
            cout << '*';
        }
        for (int j = 0; j < i * 2 + 1; j++){
            cout << 'D';
        }
        for (int j = 0; j < n / 2 - i; j++){
            cout << '*';
        }
        cout << endl;
	}
	for (int i = 0; i < n / 2; i++){
        for (int j = 0; j <= i; j++){
            cout << '*';
        }
        for (int j = 0; j < n - i * 2 - 2; j++){
            cout << 'D';
        }
        for (int j = 0; j <= i; j++){
            cout << '*';
        }
        cout << endl;
	}
}