/*
    Now he's gone, I don't know why
    And till these days sometimes I cry
    He didn't even say "Goodbye"
    He didn't take the time to lie
    ..
*/
    
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
#include<fstream>
#include<list>
#include<sstream> 
#include<cstring>
#include<bitset>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;

int n , q;
const int max_n = 2e5 + 30;
vector<int> seg(4 * max_n , -1) , vec , sec;

void shift(int v , int begin , int end , int mid){
    if (seg[v] == -1)   return;
    seg[v<<1] = seg[v];
    seg[v<<1^1] = seg[v] + (mid - begin) + 1;
    seg[v] = -1;
}

void modify(int v , int begin , int end , int a , int b , int c , int d){
    if (begin > b || end < a)   return;
    if (a < begin){c += (begin - a);    a = begin;}
    if (b > end){   d -= (b - end);     b = end;}
    if (begin == a && end == b){	 seg[v] = c;	   return;}	     

    int mid = (begin + end) / 2;
    shift(v , begin , end , mid);
    modify(v<<1 , begin , mid , a , b , c , d);
    modify(v<<1^1 , mid +1  , end , a , b , c , d);
}

int get(int v , int b , int e , int ind){
    if (b > ind || ind > e)	return -1;
    if (b == e) return  seg[v];
    
    int mid = (b + e) / 2;
    shift(v , b , e , mid);
    int first = get(v<<1 , b , mid , ind);
    int second = get(v<<1^1 , mid + 1 , e , ind);
    if (first == -1)	   return  second;
    return  first;
}

int main(){
    scanf("%d%d" , &n , &q);
    for (int i = 0 ; i < n ; i++){int temp; scanf("%d",&temp);    sec.pb(temp);}
    for (int i = 0 ; i < n ; i++){int temp; scanf("%d",&temp);    vec.pb(temp);}
    for (int i = 0 ; i < q ; i++){
	 int type;   scanf("%d" , &type);
	 if (type == 1){
	     int a , b , k;	cin >> b >> a >> k;	   a-- , b--;
	     modify(1 , 0 , n - 1 , a , a + k - 1 , b , b + k - 1);
	 }
	 else{
	     int ind;	   scanf("%d" , &ind); ind--;
	     int g = get(1 , 0 , n - 1 , ind);
	     if (g == -1)	printf("%d\n" , vec[ind]);
	     else    printf("%d\n" , sec[g]);   
	 }
    }	 
    return 0;
}