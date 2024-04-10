#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>

using namespace std;

vector<string>  vec;

void generate(int psize){
    int t = vec.size();
    for (int i = psize ; i < t ; i++){
	 vec.push_back(vec[i] + "4");
	 vec.push_back(vec[i] + "7");
    }
}

bool help(string a , string b){
    if (a.size() < b.size())    return  true;
    if (a.size() > b.size())    return  false;
    return  a < b;
}

int main(){
    string s;
    cin >> s;
    vec.push_back("4");
    vec.push_back("7");
    int size = 0 , psize;
    for (int i = 0 ; i < 10 ; i++){
	 psize = size;
	 size = vec.size();
	 generate(psize);
    }
    sort(vec.begin() , vec.end() , help);
    for (int i = 0 ; i < vec.size() ; i++)
	 if (vec[i] == s){
	     cout << i + 1 << endl;
	     return 0;
	 }
    return 0;
}