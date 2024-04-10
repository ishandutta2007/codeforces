#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<utility>

using namespace std;

string s;
int a , b;
const int max_n = 1000 * 1000 + 20;
int first[max_n];
int second[max_n];
int c[max_n];

void get_first(){
    int rem = int(s[0] - 48);
    rem %= a;
    first[0] = rem;    

    for ( int i = 1 ; i < s.size() - 1 ; i++ ){
	 rem *= 10;
	 rem += int(s[i] - 48);
	 rem %= a;
	 first[i] = rem;
    }
}

void init(){
    int rem = 10 % b;
    c[1] = rem;

    for ( int i = 2 ; i <= 1000 * 1000 ; i++ ){
	 rem *= 10;
	 rem = rem % b;
	 c[i] = rem;
    }
}

void get_second(){
    int rem = int(s[s.size() - 1] - 48);
    rem %= b;
    int j = s.size() - 2;
    second[j] = rem;
    j--;
    int p = 1;

    for ( int i = s.size() - 2 ; i > 0 ; i-- ){
	 rem += c[p] * int(s[i] - 48);
	 rem %= b;
	 second[j] = rem;
	 j--;
	 p++;
    }
    
}

void show_Ans(){    
    int p = -1;
    for ( int i = 0 ; i < s.size() - 1 ; i++ )
	 if ( first[i] == second[i] && first[i] == 0 && s[i + 1] != '0' ){
	     p = i;
	     break;
	 }

    if ( p == -1 )  cout << "NO" << endl;
    else{
	 string s1 = "";
	 string s2 = "";
	 cout << "YES" << endl;  
	 for ( int i = 0 ; i < s.size() ; i++ ){
	     if ( i <= p )	s1 += s[i];
	     else    s2 += s[i];
	 }
	 cout << s1 << endl;
	 cout << s2 << endl;
    }
}

int main(){
    cin >> s;
    cin >> a >> b;
    get_first();
    init();
    get_second();
    show_Ans();
    return 0;
}