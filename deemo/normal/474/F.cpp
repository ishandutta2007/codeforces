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

int n , m , a , b , p; 
const int max_n = 1e5 + 100;
int arr[max_n];
int seg[3 * max_n];
int mini[3 * max_n] , c[3 * max_n];
const int max_num = 1e9 + 10;

void init(int node , int begin , int end){
    if (begin == end){
	 mini[node] = arr[begin];
	 seg[node] = arr[begin];
	 c[node] = 1;
	 return;
    }
    
    int mid = (begin + end) / 2;
    init(2 * node , begin , mid);
    init(2 * node + 1 , mid + 1 , end);
    mini[node] = min(mini[2 * node] , mini[2 * node + 1]);
    seg[node] = __gcd(seg[2 * node] , seg[2 * node + 1]);
    if (mini[2 * node] == mini[2 * node + 1])   c[node] = c[2 * node] + c[2 * node + 1];
    else    if (mini[2 * node] < mini[2 * node + 1])	c[node] = c[2 * node];
    else    c[node] = c[2 * node + 1];
}

int get_mini(int node , int begin , int end , int first , int last){
    if (begin > last || end < first)    return max_num;
    if (begin >= first && end <= last)  return  mini[node];

    int mid = (begin + end) / 2;
    return  min(get_mini(2 * node , begin , mid , first , last) , get_mini(2 * node + 1 , mid + 1 , end , first , last));
}

int get(int node , int begin , int end , int first , int last){
    if (begin > last || end < first)    return  -1;
    if (begin >= first && end <= last)  return  seg[node];
    
    int mid = (begin + end) / 2;
    int a = get(2 * node , begin , mid , first , last);
    int b = get(2 * node + 1 , mid + 1 , end , first , last);
    if (a == -1)    return	b;
    if (b == -1)    return	a;
    return  __gcd(a , b);  
}

int cnt(int node , int begin , int end , int first , int last , int g){
    if (begin > last || end < first)    return  0;
    if (begin >= first && end <= last){
	 if (mini[node] == g)    return  c[node];
	 else	  return 0;
    }
    
    int mid = (begin + end) / 2;
    int a = cnt(2 * node , begin , mid , first , last , g);
    int b = cnt(2 * node + 1 , mid + 1 , end , first , last , g);
    return  a + b;
}

int main(){
    int a , b;
    cin >> n;
    for (int i = 0 ; i < n ; i++)
	 cin >> arr[i];
    init(1 , 0 , n - 1);
    cin >> m;
    for (int i = 0 ; i < m ; i++){
	 cin >> a >> b;  
	 a--;	  b--;
	 int p = get_mini(1 , 0 , n - 1 , a , b);
	 int t = get(1 , 0 , n - 1 , a , b) , w = b - a + 1;
	 if (t % p != 0){
	     cout << w << endl;
	     continue;
	 }
	 cout << w - cnt(1 , 0 , n - 1 , a , b , p) << endl;
    }
    return 0;
}