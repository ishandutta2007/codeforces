#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>	ans;

int main(){
	int n;	cin >> n;
	int cnt = 0, b = 0;
	while (n--){
		int x;	cin >> x;
		if (x < 0)
			cnt++;
		if (cnt == 3){
			ans.push_back(b);
			b =	0;
			cnt = 1;
		}
		b++;
	}
	ans.push_back(b);
	cout << (int)ans.size() << endl;
	for (int v:ans)
		cout << v << " ";
	cout << endl;
	return 0;		
}