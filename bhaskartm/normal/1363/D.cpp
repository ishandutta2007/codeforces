#include<bits/stdc++.h>
using namespace std;
 
#define vint vector<int>
 
int interact(vint S){
	cout << "? " << S.size() << ' ';
	for(int i : S)
		cout << i << ' ';
	cout << endl;
	int x;
	cin >> x;
	return x;
}
 
vint get_complement(vint v, int n){
	vint ask, occur(n + 1);
	for(int i : v)
		occur[i] = 1;
	for(int i = 1; i <= n; i++)
		if(!occur[i])
			ask.push_back(i);
	return ask;
}
 
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<vint> S(k);
		vint ans(k);
		for(int i = 0; i < k; i++){
			int c;
			cin >> c;
			S[i].resize(c);
			for(int j = 0; j < c; j++)
				cin >> S[i][j];
		}
		vint ask;
		for(int i = 1; i <= n; i++)
			ask.push_back(i);
		int max_element = interact(ask);
		//find subset with max element
		int st = 0, en = k - 1;
		while(st < en){
			int mid = (st + en) / 2;
			ask.clear();
			for(int i = 0; i <= mid; i++)
				for(int j : S[i])
					ask.push_back(j);
			int x = interact(ask);
			if(x == max_element)
				en = mid;
			else st = mid + 1;
		}
		ask = get_complement(S[st], n);
		for(int i = 0; i < k; i++)
			if(i == st)
				ans[i] = interact(ask);
			else ans[i] = max_element;
		cout << "! ";
		for(int i : ans)
			cout << i << ' ';
		cout << endl;
		string correct;
		cin >> correct;
	}
}