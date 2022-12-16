#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> arr;
vector<int> help;
int n, k;

int calls = 0;

void msc(int low, int up)
{
	if(calls >= k) return;
	if(up-low <= 1) return;

	int mid = (up+low)/2;
	
	if(calls < k) {
	
		for(int i=low;i<up;++i)
			help[i] = arr[i];
		//cerr << "FROM " << low << "-" << up << ": " << endl;
		for(int i=0;i<mid-low;++i) {
			arr[i+low] = help[low+up-mid+i];
			//cerr << arr[i+low] << " ";
		}
		for(int i=0;i<up-mid;++i) {
			arr[i+mid] = help[low+i];
			//cerr << arr[i+mid] << "(" << i+mid+low << ") ";
		}
		//cerr << endl;
		calls+= 2;
		msc(low, (up+low)/2);
		msc((up+low)/2, up);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	cin >> n >> k;
	arr.resize(n);
	help.resize(n);
	for(int i=0;i<n;++i)
		arr[i] = i+1;

	++calls;
	msc(0, n);
	if(calls != k)
		cout << -1 << endl;
	else {
		for(int i=0;i<n;++i) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	
	

	return 0;
}