#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


vector<int> lef, righ;

int main(){
    string str;
    cin >> str;
    for(int i = 0;i < str.size();i++){
	if(str[i] == 'l'){
	    lef.push_back(i + 1);
	}
	else{
	    righ.push_back(i + 1);
	}
    }
    for(int i = 0;i <  righ.size();i++){
	cout << righ[i] << endl;
    }
    for(int i = lef.size();i--;){
	cout << lef[i] << endl;
    }
    return 0;
}