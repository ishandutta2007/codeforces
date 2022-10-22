#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, k, m, x;
		cin >> n >> k >> m;
		deque <int> a, b;
		for (int i = 0; i < k; i++){
			cin >> x;
			a.push_back(x);
		}
		for (int i = 0; i < m; i++){
			cin >> x;
			b.push_back(x);
		}
		int aa = 0, bb = 0;
		sort(a.rbegin(), a.rend());
		sort(b.rbegin(), b.rend());
		while(a.size() && b.size()){
			if(a[0] > b[b.size() - 1]){
				a.push_back(b[b.size() - 1]);
				b.pop_back();
				aa ++;
			}else{
				b.push_back(a[0]);
				a.pop_front();
				bb ++;	
			} 
		}
		if (aa > bb){
			cout  << "YES" << endl;
		}else{
			cout << "NO" << endl;
		} 
	}   
}