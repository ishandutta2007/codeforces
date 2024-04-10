#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> ans;
int m;
int main(){
	cin >> m;
	int cnt5 = 0;
	for(int i = 1;i <= m * 5 + 10;i++){
		int t = i;
		while(t % 5 == 0){
			cnt5++;
			t /= 5;
		}
		if(cnt5 == m)ans.push_back(i);
		if(cnt5 > m)break;
	}	
	cout << ans.size() << endl;
	for(int i = 0;i < ans.size();i++){
		if(i)cout << " ";
		cout << ans[i];
	}                  cout << endl;
	return 0;
}