#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>
#include<utility>
#include<map>
#include<stack>

using namespace std;

string s;

int main(){
    cin >> s;
    char c = s[s.size() - 1];
    char temp;
    int ind = -1 , flag = 0 , fl = 0;
    for ( int i = 0 ; i < s.size() ; i++ ){
	 temp = s[i];
	 if ( int(temp) % 2 == 0 ){
	     flag = 1;
	     if ( temp < c ){
		  s[i] = c;
		  s[s.size() - 1] = temp;
		  fl = 1;
		  break;
	     }
	     else    ind = i;
	 }
    }
    if ( flag == 0 )	   cout << -1 << endl;
    else{
	 if ( fl == 1 )	cout << s << endl;
	 else{
	     s[s.size() - 1] = s[ind];
	     s[ind] = c;
	     cout << s << endl;
	 }
    }	 
    return 0;

}