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

int s1 , s2 , d , sum , a[50] , b[50];

int main(){
    cin >> d >> sum;	   
    for (int i = 0 ; i < d ; i++){
	 cin >> a[i];
	 cin >> b[i];	 
	 s1 += a[i];
	 s2 += b[i];
    }
    if (s1 > sum || s2 < sum){
	 cout << "NO" << endl;
	 return 0;
    }

    sum -= s1;
    int i = 0;
    while (sum > 0){
	 if (a[i] == b[i])	i++;
	 else{
	     a[i] += 1;
	     sum--;
	 }
    }	 

    cout << "YES" << endl;
    for (int i = 0 ; i < d ; i++)
	 cout << a[i] << " ";
    cout << endl;
    
    return 0;
}