#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<iomanip>
#include<stack>
#include<queue>

using namespace std;

int main(){
    string s;
    cin >> s;
    int flag = 0;
    for ( int i = 0 ; i < s.size() ; i++ ){
	 if ( s[i] > '4' && ( flag == 1 || s[i] != '9' )  )	s[i] = ( 57 - s[i] ) + 48;
	 flag = 1;
    }   
    
    cout << s << endl;
    return 0;
}