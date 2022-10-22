#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

const int max_n = 90 + 10;
int first_Team[max_n];
int second_Team[max_n];
string team1 , team2;
int n;

void input(){
    cin >> team1 >> team2;
    cin >> n;
    
}


void get_Ans(){
    int time , number;
    char t , card;
    
    for ( int i = 0 ; i < n ; i++ ){
	 cin >> time >> t >> number >> card;

	 if ( ( t == 'h' ) && ( first_Team[number] < 2 ) ){
	     if ( card == 'y' )  first_Team[number] += 1;
	     else first_Team[number] += 2;
	     if ( first_Team[number] > 1 )	  cout << team1 << " " << number << " " << time << endl;

	 }
	 if ( ( t == 'a' ) && ( second_Team[number] < 2 ) ){
	     if ( card == 'y' )  second_Team[number] += 1;
	     else    second_Team[number] += 2;
	     if ( second_Team[number] > 1 )  cout << team2 << " " << number << " " << time << endl;

	 }
	 

    }

}


int main(){
    input();
    get_Ans();
    return 0;

}