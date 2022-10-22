#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<string>

using namespace std;

string s;
int sum1 , sum2 , sum3;
int x , flag;
vector<int> ans;

void input(){
    cin >> s;
    for ( int i = 0 ; i < s.size() ; i++ ){
	 if ( s[i] == '(' )	sum1++;
	 if ( s[i] == ')' )	sum2++;
	 if ( s[i] == '#' )	sum3++;
	 if ( sum1 < sum2 + sum3 )	 flag = 1;

    }
    x = sum1 - sum2;

}


void get_Ans(){
    for ( int i = 0 ; i < s.size() ; i++ ){
	 if ( sum3 == 1 ){
	     ans.push_back(x);
	     break;
	 }
	 
	 if ( s[i] == '#' ){
	     ans.push_back(1);   
	     x--;
	     sum3--;

	 }

    }

}


void show_Ans(){
    for ( int i = 0 ; i < ans.size() ; i++ )
	 cout << ans[i] << endl;

}


int main(){
    input();
    if ( flag == 1 )	   cout << -1 << endl;
    else{
        get_Ans();
	 int fl = 0;
	 int ind = 0;
	 sum1 = sum2 = sum3 = 0;
	 
	 for ( int i = 0 ; i < s.size() ; i++ ){
	     if ( s[i] == '(' )  sum1++;
	     if ( s[i] == ')' )  sum2++;
	     if ( s[i] == '#' ){
		  sum3 += ans[ind];
		  ind++;

	     }

	     if ( sum1 < sum2 + sum3 ){
		  fl = 1;
		  break;

	     }

	 }
	 if ( fl == 1 )	cout << -1 << endl; 
	 else show_Ans();

    }

    return 0;

}