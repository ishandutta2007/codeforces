#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<utility>
#include<vector>

using namespace std;

int n;
const int max_n = 2 * 1000 * 100 + 100;
vector<int> vec;
vector<int> arr[max_n];
vector<int> ans;

void input(){
    cin >> n;
    int temp;
    for ( int i = 0 ; i < n ; i++ ){
	 cin >> temp;
	 vec.push_back(temp);
	 arr[temp].push_back(i);
    }	 
}

void show_Ans(){
    cout << "Possible" << endl;
    for ( int i = 0 ; i < ans.size() - 1 ; i++ )
	 cout << ans[i] << " ";
    cout << ans[ans.size() - 1] << endl;
}   

int main(){
    input();
    int present = 0 , q = 0;
    
    for ( int i = 0 ; i < n ; i++ ){
	 if ( present < 3 ){
	     if ( arr[present].size() <= 0 ){
		  cout << "Impossible" << endl;
		  return 0;
	     }
	     else{
		  ans.push_back(arr[present].back() + 1);
		  arr[present].pop_back();
		  present += 1;
	     }
	 }

	 else	  if ( present >= 3 ){
	     
	     while ( arr[present].size() == 0 && present >= 3 ){
		  present -= 3;
	     }

	     if ( arr[present].size() > 0 ){
		  ans.push_back(arr[present].back() + 1);
		  arr[present].pop_back();
		  present += 1;	      
	     }
	     else{
		  cout << "Impossible" << endl;
		  return 0;
	     }	  
    
	 }
	 
    }
    show_Ans();
    
    return 0;
}