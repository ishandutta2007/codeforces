#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

int n ;
vector<string>  vec;

void input(){
    cin >> n;
    string s;

    for ( int i = 0 ; i < n ; i++ ){
	 cin >> s ;
	 vec.push_back(s);
    }

}
long long int ans = 1;
void get_Ans(){
    for ( int i = 0 ; i  < vec.size() - 1 ; i++ ){
	 if ( vec[i] != vec[i + 1] ) ans++;

    }
}


int main(){
    input();
    get_Ans();
    cout << ans << endl;
    return 0;

}