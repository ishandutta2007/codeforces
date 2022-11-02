#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >a;
set<pair<int,int> >st;
int main(){
	for(int i = 0; i < 3; i++){
		int x, y;
		cin >> x >> y;
		a.push_back(make_pair(x,y));
	}
	sort(a.begin(),a.end());
	do{
		int x = a[1].first - a[0].first + a[2].first;
		int y = a[1].second - a[0].second + a[2].second;
		st.insert(make_pair(x,y));
	}while(next_permutation(a.begin(), a.end()));

	cout << st.size() << endl;
	for(auto x: st){
		cout << x.first <<" "<< x.second <<endl;
 	}
 	//system("pause");
 	return 0;
}