#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<utility>

using namespace std;

vector<int> vec;
string ans;

void get(int ind , char c){
    for ( int i = ind ; i < ans.size() ; i++ )
	 ans[i] = c;
}

int main(){
    string s1 , s2;
    cin >> s1 >> s2;
    int flag = 0;
	 
    for ( int i = 0 ; i < s1.size() ; i++ ){
	 if ( s1[i] != s2[i] ){
	     ans = s1;
	     if ( s2[i] != s1[i] + 1 )   ans[i] += 1;
	     get(i + 1 , 'z');
	     if ( ans != s1 ){
		  flag = 1;
		  break;
	     }
	     else    break;
	 }
    }	     

    if ( flag == 0 ){   
	 for ( int i = 0 ; i < s1.size() ; i++ ){
	     if ( s1[i] != s2[i] ){
		  ans = s2;
		  get(i + 1 , 'a');
    
		  if ( ans != s2 )	 flag = 1;   
		  break;
	     }
    
	 }
    
    }

    if ( flag == 0 )	   cout << "No such string" << endl;
    else    cout << ans << endl;
    

    return 0;
}