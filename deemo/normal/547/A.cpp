#include<iostream>
#include<cstdio>
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

const int max_n = 1e6 + 30;
int arr[max_n] , b[max_n];
long long int m , h1 , h2 , a1 , a2 , x1 , x2 , y1 , y2 , n1 , n2 , z1 , z2;
vector<int> c;

int main(){
    cin >> m;
    cin >> h1 >> a1 >> x1 >> y1;
    cin >> h2 >> a2 >> x2 >> y2;
    
    long long int k = h1;
    while (arr[k] == 0){
	 if (k == a1)	   z1 = n1;
	 arr[k] = n1 + 1;
	 k = (long long)(x1 * k + y1) % m;
	 n1++;
    }
    n1 = n1 - arr[k] + 1;
    bool fl = arr[k] - 1 > z1;
    
    if (z1 == 0){
	 cout << -1 << endl;
	 return 0;
    }

    k = h2;
    while (b[k] == 0){
	 if (k == a2)	   z2 = n2;
	 b[k] = n2 + 1;
	 k = (long long)(x2 * k + y2) % m;
	 n2++;
    }
    n2 = n2 - b[k] + 1;
    c.push_back(k);
    int t = k;
    k = (long long)(x2 * k + y2) % m;
    while (k != t){
	 c.push_back(k);
	 k = (long long)(x2 * k + y2) % m;
    }
    
    if (z2 == 0){
	 cout << -1 << endl;
	 return 0;
    }	 

    if (z2 == z1){
	 cout << z2 << endl;
	 return 0;
    }
    
    if (fl == 1){
	 cout << -1 << endl;
	 return 0;
    }

    z2 = 0;
    long long ans = 0;

    for (int i = 0 ; i < b[k] - 1 ; i++){
	 h1 = (long long)(x1 * h1 + y1) % m;
	 h2 = (long long)(x2 * h2 + y2) % m;
	 if (z1 == 0)	   z1 = n1 - 1;
	 else	  z1--;
	 ans++;
	 if (h1 == a1 && h2 == a2){
	     cout << ans << endl;
	     return 0;
	 }
    }

    for (int i = 0 ; i < z1 ; i++){
	 h1 = (long long)(x1 * h1 + y1) % m;
	 h2 = (long long)(x2 * h2 + y2) % m;
	 z2 = (z2 + 1) % n2;
	 ans++;
	 if (h1 == a1 && h2 == a2){
	     cout << ans << endl;
	     return 0;
	 }
    }	 

    for (int i = 0 ; i < 1e7 ; i++){
	 z2 = (z2 + n1) % n2;
	 ans += n1;
	 if (c[z2] == a2)	   break;
    }
    if (c[z2] != a2){
	 cout << -1 << endl;
	 return 0;
    }	 
    cout << ans << endl;
    return 0;
}