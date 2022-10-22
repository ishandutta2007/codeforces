#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	string s;
    cin >> n >> s;
    for(int i = n - 1; i >= 0; i--){
        if(n % 2 == i % 2){
        	cout << s[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(n % 2 != i % 2){
        	cout << s[i];
        }
    }
}