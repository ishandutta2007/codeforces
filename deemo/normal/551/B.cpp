#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>

using namespace std;

string a , b , c;
vector<char>	  ans , aans;
int arr[400] , barr[400] , carr[400];
int g , h;

int main(){
    cin >> a >> b >> c;
    for (int i = 0 ; i < a.size() ; i++)
	 arr[a[i]] += 1;

    if (c.size() > b.size()){
	 string temp = c;
	 c = b;
	 b = temp;
    }

    for (int j = 0 ; j < c.size() ; j++)
	 carr[c[j]] += 1;    
    int maxi = -1 , ind , max_ind , fl = 0;
    for (int i = 0 ; i < a.size() / b.size() ; i++){//inghadr ta b bashe
	 for (int j = 0 ; j < 300 ; j++)
	     barr[j] = arr[j];
	 
	 for (int j = 0 ; j < b.size() ; j++){
	     barr[b[j]] -= i;
	     if (barr[b[j]] < 0){
		  fl = 1;
		  break;
	     }
	 }
	 if (fl == 1)	   break;

	 int mini = 1e6;

	 for (int j = 0 ; j < c.size() ; j++)
	     mini = min(mini , barr[c[j]] / carr[c[j]]);  

	 if (mini + i > maxi){
	     maxi = mini + i;
	     ind = i;
	     max_ind = mini;
	 }   
    }
    if (maxi == -1) maxi = ind = max_ind = 0;

    for (int i = 0 ; i < ind ; i++)
	 for (int j = 0 ; j < b.size() ; j++){
	     arr[b[j]] -= 1;
	     ans.push_back(b[j]);
	 }
    for (int i = 0 ; i < max_ind ; i++){
	 for (int j = 0 ; j < c.size() ; j++){
	     arr[c[j]] -= 1;
	     ans.push_back(c[j]);
	 }
    }
    for (int i = 0 ; i < 300 ; i++){
	 for (int j = 0 ; j < arr[i] ; j++)
	     ans.push_back(char(i));
    }
    for (int i = 0 ; i < ans.size() ; i++)
	 cout << ans[i];
    cout << endl;

    return 0;
}