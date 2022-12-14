#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		bool k = 1;
		vector<char> in;
		//A = 0 , B = 1 , C = 0
		for(char i : s){
			if(in.size() && i == 'B'){
				if(in.back() != 'B') in.pop_back();
				else in.push_back(i);
			}
			else in.push_back(i);
		}
		if(in.size()) k = 0;

		bool kk = 1;
		in.clear();
		//A = 0 , B = 0 , C = 1
		for(char i : s){
			if(in.size() && i == 'C'){
				if(in.back() != 'C') in.pop_back();
				else in.push_back(i);
			}
			else in.push_back(i);
		}
		if(in.size()) kk = 0;

		bool kkk = 1;
		in.clear();
		//A = 1 , B = 0 , C = 0
		for(char i : s){
			if(in.size() && i == 'A'){
				if(in.back() != 'A') in.pop_back();
				else in.push_back(i);
			}
			else in.push_back(i);
		}
		if(in.size()) kkk = 0;

		bool kkkk = 1;
		in.clear();
		//A = 1 , B = 0 , C = 1
		for(char i : s){
			if(in.size() && (i == 'A' || i == 'C')){
				if(in.back() == 'B') in.pop_back();
				else in.push_back(i);
			}
			else in.push_back(i);
		}
		if(in.size()) kkkk = 0;

		bool kkkkk = 1;
		in.clear();
		//A = 1 , B = 1 , C = 0
		for(char i : s){
			if(in.size() && (i == 'A' || i == 'B')){
				if(in.back() == 'C') in.pop_back();
				else in.push_back(i);
			}
			else in.push_back(i);
		}
		if(in.size()) kkkkk = 0;

		bool kkkkkk = 1;
		in.clear();
		//A = 0 , B = 1 , C = 1
		for(char i : s){
			if(in.size() && (i == 'B' || i == 'C')){
				if(in.back() == 'A') in.pop_back();
				else in.push_back(i);
			}
			else in.push_back(i);
		}
		if(in.size()) kkkkkk = 0;
		if(k || kk || kkk || kkkk || kkkkk || kkkkkk) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}