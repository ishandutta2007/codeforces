#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

string s1, s2, s3;

int main(){
	cin >> s1 >> s2 >> s3;
	sort(s3.begin(), s3.end());
	string t = s1 + s2;
	sort(t.begin(), t.end());
	t == s3? cout << "YES" << endl : cout << "NO"<< endl;
	return 0;
}