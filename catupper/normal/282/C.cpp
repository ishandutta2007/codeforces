#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>


using namespace std;

string str1 ,str2;

int main(){
    cin >> str1;
    cin >> str2;
    if(str1.size() != str2.size()){
	cout << "NO" << endl;
	return 0;
    }
    bool res1 = false, res2 = false;
    for(int i = 0;i < str1.size();i++){
	if(str1[i] == '1')res1 = true;
	if(str2[i] == '1')res2 = true;
    }
    if(res1 == res2)cout << "YES" << endl;
    else cout <<"NO" << endl;
    return 0;
}