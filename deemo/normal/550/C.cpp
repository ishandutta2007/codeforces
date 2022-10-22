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

string s;
deque<char>	  vec;

int get(deque<char> temp){
    int ret = 0;
    int i = 0;
    int e = 1;
    while (temp.size() != 0 && i < 3){
	 ret = (int(temp.back()) - 48) * e + ret;
	 temp.pop_back();
	 i++;
	 e *= 10;
    }

    return  ret;
}

int main(){
    cin >> s;
    for (int i = 0 ; i < s.size() ; i++)
	 vec.push_back(s[i]);
    int size = s.size();
    for (int i = 0 ; i < size ; i++){
	 int x = get(vec);
	 if (x % 8 == 0){
	     cout << "YES" << endl;
	     for (int i = 0 ; i < vec.size() ; i++)
		  cout << vec[i];
	     cout << endl;
	     return 0;
	 }
    
	 if (x % 2 != 0) vec.pop_back();
	 else{
	     if (x % 4 != 0 && vec.size() > 1){
		  char c = vec.back();
		  vec.pop_back(); vec.pop_back();
		  vec.push_back(c);
	     } 
	     else if (vec.size() > 2){
		  char c = vec[vec.size() - 1];   vec.pop_back();
		  char d = vec[vec.size() - 1];   vec.pop_back();
		  vec.pop_back();
		  vec.push_back(d);
		  vec.push_back(c);
	     }
	 }
    }
    cout << "NO" << endl;
    return 0;
}