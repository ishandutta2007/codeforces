#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> vec;

void input(){
    cin >> n;
    int temp;

    for ( int i = 0 ; i < n ; i++ ){
	 cin >> temp;
	 vec.push_back(temp);
    }	 
    sort(vec.begin() , vec.end());
}

int main(){
    input();
    if ( n == 2 ){
	 cout << vec[1] << " " << vec[0] << endl;
	 return 0;
    }
    
    cout << vec[vec.size() - 1] << " ";
    for ( int i = 1 ; i < vec.size() - 1 ; i++ )
	 cout << vec[i] << " ";
    cout << vec[0] << endl;
    return 0;
}