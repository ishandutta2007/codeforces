#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;


long long int sum1 , sum2 , n , t;
vector<int> vec1;
vector<int> vec2;


void input(){
    cin >> n;
    long long  int temp;

    for ( int i = 0 ; i < n ; i++ ){
	 cin >> temp;
	 if ( temp > 0 ){
	     sum1 += temp;
	     vec1.push_back(temp);
	     t = 1;

	 }
	 else{
	     sum2 += -temp;
	     vec2.push_back(-temp);
	     t = 2;

	 }

    }

}

long long int flag;

void get_It(){
    long long int sz = min( vec1.size() , vec2.size() );

    for ( long long int i = 0 ; i < sz ; i++ ){
	 if ( vec1[i] > vec2[i] ){
	     flag = 1;
	     return;

	 }
	 if ( vec2[i] > vec1[i] ){
	     flag = 2;
	     return;

	 }

    }
    

}


int main(){
    input();
    if ( sum1 > sum2 ) cout << "first" << endl;
    else    if ( sum1 < sum2 )  cout << "second" << endl;
    else{
	 get_It();
	 if ( flag == 1 )	cout << "first" << endl;
	 else if ( flag == 2 )   cout << "second" << endl;
	 else if ( t == 1 )	cout << "first" << endl;
	 else	  cout << "second" << endl;

    }
    return 0;

}