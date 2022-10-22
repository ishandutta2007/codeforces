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

map<string , bool>   mp;

bool check(queue<int>   saf1 , queue<int>	  saf2){
    string ret = "";
    while (!saf1.empty()){
	 if (saf1.front() == 10)  ret += 'x';
	 else	  ret += char(saf1.front() + 48);
	 saf1.pop();
	 ret += '-';
    }
    ret += '|';
    while (!saf2.empty()){
	 if (saf2.front() == 10) ret += 'x';
	 else	  ret += char(saf2.front() + 48);
	 saf2.pop();
	 ret += '-';
    }
    if (mp[ret] == 1)   return  true;
    mp[ret] = 1;
    return  false;
}

int main(){
    int n , k1 , k2 , temp;
    queue<int>  saf1 , saf2;
    cin >> n >> k1;
    for (int i = 0 ; i < k1 ; i++){
	 cin >> temp;
	 saf1.push(temp);
    }
    cin >> k2;
    for (int i = 0 ; i < k2 ; i++){
	 cin >> temp;
	 saf2.push(temp);
    }	 
    temp = check(saf1 , saf2);

    int t1 , t2 , k = 1;
    while(1){
	 t1 = saf1.front();
	 saf1.pop();
	 t2 = saf2.front();
	 saf2.pop();
	 if (t1 > t2){
	     saf1.push(t2);
	     saf1.push(t1);
	     if (saf2.empty()){
		  cout << k << " " << 1 << endl;
		  return 0;
	     }	  
	 }
	 else{
	     saf2.push(t1);
	     saf2.push(t2);
	     if (saf1.empty()){
		  cout << k << " " << 2 << endl;
		  return 0;
	     }
	 }
	 if (check(saf1 , saf2)){
	     cout << -1 << endl;
	     return 0;
	 }
	 k++;
    }

    return 0;
}