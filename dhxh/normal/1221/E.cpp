#include <bits/stdc++.h>

using namespace std;

int t;
string str;
vector <int> vec;
int a, b;

int main(){
	int i, j;
	
	cin >> t;
	
	while(t--){
		cin >> a >> b;
		cin >> str;
		vec.clear();
		vec.push_back(0);
		for(auto x : str){
			if(x == 'X'){
				if(vec.back())vec.push_back(0);
			}else{
				vec.back()++;
			}
		}
		if(vec.size() and !vec.back())vec.pop_back();
		
		int cnta = 0, cntb = 0, cntc = 0, cntd = 0;
		int maxx = 0;
		
		for(auto x : vec){
			if(x < a and x >= b){
				cntb += x / b;
			}
		}
		
		for(auto x : vec){
			if(x >= a){
				cnta++;
			}
			
			if(x >= 2 * b){
				cntd++;
				maxx = max(maxx, x);
			}
		}
		
		if(cntb or cntd >= 2){
			cout << "NO" << endl;
		}else if(cntd == 0){
			if(cnta % 2 == 1) cout << "YES" << endl;
			else cout << "NO" << endl;
		}else{
			bool flag = false;
			for(i=0;i+a<=maxx;i++){
				int tmp = cnta - 1;
				if(i >= b and i < a)continue;
				if(maxx - i - a >= b and maxx - i - a < a)continue;
				if(i >= 2 * b or maxx - i - a >= 2 * b)continue;
				if(i >= a)tmp++;
				if(maxx - i - a >= a)tmp++;
				if(tmp % 2 == 0){
					flag = true;
					break;
				}
			}
			if(flag) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		
		
	}
	
	return 0;
}