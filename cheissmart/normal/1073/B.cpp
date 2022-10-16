#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 87;

int a[N], b[N], inbp[N];

int main()
{
	int n;
	cin >> n;
	for (int i=0;i<n;i++)
		cin >> a[i];
	for (int i=0;i<n;i++)
		cin >> b[i];
	int st = 0;
	for (int i=0;i<n;i++) {
		if(inbp[b[i]]){
			cout << 0 << " ";
			continue;	
		}
		for(int j=st;j<n;j++) {
			inbp[a[j]] = 1;
			if(a[j] == b[i]) {
				cout << j - st + 1 << " ";
				st = j+1;
				break;
			}
		}
	}
}