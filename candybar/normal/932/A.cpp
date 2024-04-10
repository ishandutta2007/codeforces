#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
string s;
int main(){
	cin >> s;
	cout<<s;
	for(int i=s.size()-1;i>=0;i--){
		cout<<s[i];
	}
	cout<<endl;
	return 0;
}