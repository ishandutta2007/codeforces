#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

const long long int max_n = 2 * 100 * 1000 + 10;
vector<long long int> vec1;
vector<long long int> vec2;
long long int n , m , score1 , score2;


void input(){
    cin >> n;
    long long int temp;

    for ( long long int i = 0 ; i < n ; i++ ){
	 cin >> temp;
	 score1 += temp;
	 vec1.push_back(temp);
	 
    }
    sort( vec1.begin() , vec1.end() );

    cin >> m;
    
    for ( long long int i = 0 ; i < m ; i++ ){
	 cin >> temp;
	 score2 += temp;
	 vec2.push_back(temp);

    }
    sort( vec2.begin() , vec2.end() );

}


int max_a , max_b ;

void get_Ans(){
    long long int p1 = 0, p2 = 0;
    long long int i = vec1.size() - 1 , j = vec2.size() - 1;
    long long int x;

    while ( i >= 0 ){
	 x = vec2[j];
	 vec2.pop_back();
	 j--;
	 
	 if ( j == -1 ){
	     
	     if ( vec1[0] <= x ) p2++;
	     p1 += i + 1;
	     if ( ( p1 - p2 ) >= ( max_a - max_b ) ){
		  max_a = p1;
		  max_b = p2;

	     }

	     return;
	 }

	 while ( vec1[i] > x ){
	     p1++;
	     vec1.pop_back();
	     i--;
	     if ( i == -1 )	break;

	 }


	 if ( ( p1 - p2 )  >= ( max_a - max_b ) ){
	     max_a = p1;
	     max_b = p2;

	 }
	 p2++;

    }

}


int main(){
    input();
    get_Ans();
    cout << ( 2 * n ) + max_a << ":" << ( 2 * m ) + max_b << endl;
    
    return 0;

}