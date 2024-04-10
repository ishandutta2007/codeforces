#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 20;

int n, m;
int vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;	for (int i = 0; i < n; i++)	cin >> vec[i];	sort(vec, vec + n);	reverse(vec, vec + n);
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += vec[i];
		if (sum >= m){
			cout << i + 1 << endl;
			return	0;
		}	
	}
	return	0;
}