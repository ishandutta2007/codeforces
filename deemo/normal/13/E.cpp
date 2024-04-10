/*
    I found myself in Wonderland
    Get back on my feet again..
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

const int max_n = 1e5 + 10;
const int SQRT = 350;

int n , q;
vector<int> vec;
int last[max_n] , cnt[max_n];

void op(int ind){
    if ((ind + vec[ind]) / SQRT > ind / SQRT || ind + vec[ind] >= n){
	 cnt[ind] = 1;
	 last[ind] = ind;
    }	  
    else{
	 cnt[ind] = cnt[ind + vec[ind]] + 1;
	 last[ind] = last[ind + vec[ind]];
    }
}

void init(){
    for (int i = 0 ; i < n ; i += SQRT){
	 int ind = min(i + SQRT - 1 , n - 1);
	 while (ind >= i){
	     op(ind);
	     ind--;
	 } 
    }
}

void modify(int ind , int val){
    vec[ind] = val;
    int x = (ind / SQRT) * SQRT + SQRT - 1;
    x = min(x , n - 1);
    while (x >= 0 && x / SQRT == ind / SQRT){
	 op(x);
	 x--;
    }
}

void show_res(int ind){
    int ans = 0 , pre;
    while (ind < n){
	 pre = last[ind] + 1;
	 ans += cnt[ind];
	 ind = last[ind] + vec[last[ind]];
    }
    //cout << pre << " " << ans << endl;
    printf("%d %d\n" , pre , ans);
}

int main(){
    read_fast;
    scanf("%d%d" , &n , &q);
    vec.resize(n);
    for (int i = 0 ; i < n ; i++)	 scanf("%d" , &vec[i]);//cin >> vec[i];
    init();
    while (q--){
	 int type;   scanf("%d" , &type);//cin >> type;
	 if (!type){
	     int ind , val;	scanf("%d%d" , &ind , &val);  ind--;
	     modify(ind , val);
	 }
	 else{
	     int ind;  scanf("%d" , &ind);	 ind--;
	     show_res(ind);
	 }
    }
    return 0;
}