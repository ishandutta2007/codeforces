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

int n , m , k;

void create(int begin){
    for (int i = begin ; i < begin + k ; i++)
	 for (int j = begin + k ; j < begin + 2 * k ; j++){
	     if (i == begin + k - 1 && j == begin + 2 * k - 1)	 continue;
	     printf("%d %d\n" , i , j);
	 }
}

int main(){
    cin >> k;
    if (k % 2 == 0){
    	 cout << "NO" << endl;
	 return 0;
    }
    cout << "YES" << endl;
    n = (4 * k) * int(k / 2) + 2;
    m = (n * k) / 2;
    cout << n << " " << m << endl;
    cout << 1 << " " << 2 << endl;
    for (int i = 0 ; i < k / 2 ; i++){
	 create(i * 2 * k + 3);
	 printf("%d %d\n" , 1 , (i * 2 * k + 3) +k - 1);
	 printf("%d %d\n" , 1 , (i * 2 * k + 3) +2 * k - 1);
    }
    
    for (int i = k / 2 ; i < int(k / 2) + int(k / 2) ; i++){
	 create(i * 2 * k + 3);
	 printf("%d %d\n" , 2 , (i * 2 * k + 3) +k - 1);
	 printf("%d %d\n" , 2 , (i * 2 * k + 3) +2 * k - 1);
    }
    return 0;
}