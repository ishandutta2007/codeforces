#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>

using namespace std;

int n;
vector<int> vec;

void input(){
    cin >> n;
    int temp;

    for ( int i = 0 ; i < n ; i++ ){
	 cin >> temp;
	 vec.push_back(temp);

    }

}

int main(){
    input();
    
    int t1 , t2 , t3;
    t1 = t2 = t3 = 0;

    for ( int i = 0 ; i < vec.size() ; i++ ){
	 if ( vec[i] == 25 )	    t1++;
	 if ( vec[i] == 50 ){
	     t2++;
	     if ( t1 < 1 ){
		  cout << "NO" << endl;
		  return 0;
	     
	     }
	     else t1--;
	 }
	 if ( vec[i] == 100 ){
	     t3++;
	     if ( t2 > 0 ){
		  t2 -= 1;
		  vec[i] -= 50;
	     }
	     t1 -= ( vec[i] / 25 ) - 1;
	     if ( t1 < 0 ){
		  cout << "NO" << endl;
		  return 0;
	     }	  
	 
	 }

    }    
    
    cout << "YES" << endl;

    return 0;

}