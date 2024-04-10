#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>

using namespace std;

string aa, bb;

void move(vector<char> &str, int from, int size){
	if(size % 2 == 1)return;
	int rfrom = from + size / 2;
	move(str, from, size / 2);
	move(str, rfrom, size / 2);
	for(int i = 0;i < size / 2;i++){
		if(str[from + i] == str[rfrom + i])continue;
		if(str[from + i] < str[rfrom + i])break;
		if(str[from + i] > str[rfrom + i]){
			for(int j = 0;j < size/2;j++){
				swap(str[from+j], str[rfrom+j]);
			}
			break;
		}
	}
	return;
}

int main(){
	cin >> aa >> bb;
	int n = aa.size();
	vector<char> a, b;
	for(int i = 0;i < n;i++){
		a.push_back(aa[i]);
		b.push_back(bb[i]);
	}
	
	move(a, 0, n);
	move(b, 0, n);
	
	if(a == b){
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;
	return 0;	
}