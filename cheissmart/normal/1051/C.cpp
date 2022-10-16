#include <bits/stdc++.h>

using namespace std;
int in[105], a[105];

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> in[i];
		a[in[i]]++;
	}
	int ct = 0, oct = 0;
	for(int i=1;i<=100;i++) {
		if(a[i] == 1)
			ct++;
		else if(a[i] > 2)
			oct++;
	}
	
	if(ct % 2 && oct == 0) {
		cout << "NO" << endl;
	} else if(ct % 2) {
		cout << "YES" << endl;
		bool f = 1;
		bool f2 = true;
		for(int i=0;i<n;i++) {
			if(a[in[i]] == 1) {
				cout << (f ? "A" : "B");
				f = !f;
			} else if(a[in[i]] > 2 && f2){
				cout << "B";
				f2 = false;
			} else if(a[in[i]] == -1){
				cout << "A";
			} else {
				cout << "A";
			}
		}
		cout << endl;
	} else {
		cout << "YES" << endl;
		bool f = 1;
		for(int i=0;i<n;i++) {
			if(a[in[i]] == 1) {
				cout << (f ? "A" : "B");
				f = !f;
			} else {
				cout << "A";
			}
		}
		cout << endl;
	}
}