#include<iostream>
#include<string>

using namespace std;

int temp;
string s;
int arr[300];
int ans;

int main(){
    cin >> temp >> s;
    
    for ( int i = 0 ; i < s.size() ; i++ ){
	 if ( s[i] > 90 )	s[i] -= 32;
	 if ( arr[s[i]] == 0 )   ans++;

	 arr[s[i]] += 1;	
    }

    if ( ans == 26 )	   cout << "YES" << endl;
    else    cout << "NO" << endl;

    return 0;	  
}