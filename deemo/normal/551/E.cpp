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

typedef long long ll;
vector<ll>  vec;
const int max_n = 6 * 1e5;
ll d[1000];
vector<int> sec[1000];
int n , q;
int k;

void init(){
    for (int i = 0 ; i < n + k ; i += k){
	 if (i >= n)  return;
	 sec[i / k].assign(vec.begin() + i , min(vec.end() , vec.begin() + i + k));
	 sort(sec[i/k].begin() , sec[i/k].end());
    }
}

void update(int l , int r , int x){
    int z = (l / k) * k , i;
    for (i = z ; i < n && i < z + k ; i++)
	 if (i >= l && i <= r) vec[i] += x;
    sec[z/k].assign(vec.begin() + z , min(vec.end() , vec.begin() + z + k));
    sort(sec[z/k].begin() , sec[z/k].end());


    for (int j = l/k + 1 ; j < r/k ; j++)
	 d[j] += x;
    
    z = (r/k) * k;
    if (z == (l/k) * k) return;
    for (int j = z ; j < min(z + k , n) ; j++)
	 if (j >= l && j <= r)   vec[j] += x;
    sec[z/k].assign(vec.begin() + z , min(vec.end() , vec.begin() + z + k));
    sort(sec[z/k].begin() , sec[z/k].end());

}

int get_min(int y){
    for (int i = 0 ; i < n + k ; i += k){
	 if (i >= n)  return -1;
	 int a = 0 , b = sec[i/k].size() - 1 , c = -1;
	 while (a <= b){
	     int mid = (a + b)/2;
	     if (sec[i/k][mid] + d[i/k] == y)    c = mid;
	     else    if (sec[i/k][mid] + d[i/k] < y)   a = mid + 1;
	     else    b = mid - 1;
	     if (c != -1)	break;
	 } 
	 if  (c != -1)
	     for (int j = i ; ; j++)
		  if (vec[j] + d[i/k] == y)	  return  j;
    } 
    return  -1;
}

int get_max(int y){
    for (int i = n - 1 ; i >= 0 ; i -= k){
	 if (i < 0)  return -1;
	 int a = 0 , b = sec[i/k].size() - 1 , c = -1;
	 while (a <= b){
	     int mid = (a + b)/2;
	     if (sec[i/k][mid] + d[i/k] == y)    c = mid;
	     else    if (sec[i/k][mid] + d[i/k] < y)   a = mid + 1;
	     else    b = mid - 1;
	     if (c != -1)	break;
	 } 
	 if (c != -1)
	     for (int j = min((i/k) * k + k - 1 , n - 1) ; ; j--)
		  if (vec[j] + d[i/k] == y)	  return  j;
    } 
    return  -1;
}

int get(int y){
    int a = get_min(y);
    int b = get_max(y);
    if (a == -1)    return	-1;
    return  b - a;
}

int main(){
    scanf("%d %d" , &n , &q);
    k = sqrt(n);
    int temp;
    for (int i = 0 ; i < n ; i++){
	 scanf("%d" , &temp);
	 vec.push_back(temp);
    }
    init();
    
    int type , l , r , x , y;
    for (int i = 0 ; i < q ; i++){
	 scanf("%d" , &type);
	 if (type == 2){
	     scanf("%d" , &y);
	     printf("%d\n" , get(y));
	 }
	 else{
	     scanf("%d %d %d" , &l , &r , &x);
	     l--;    r--;
	     update(l , r , x);
	 }
    }
    return 0;
}