#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>

using namespace std;

int n , k;
const int max_n = 2000 + 10;
int d[max_n][max_n];
long long int ans;
vector<int> vec[max_n];
const int q = 1000000007;

void input(){
    cin >> n >> k;
}

long long int get(int p , int m){
    if (m == 0) d[p][m] = 1;
    if ( d[p][m] == -1 )	return 0;
    if ( d[p][m] != 0 ) return d[p][m];

    long long int temp = 0;
    int v;
    for ( int i = 0 ; i < vec[p].size()  ; i++ ){
	 v = vec[p][i];
	 temp += get(v , m - 1);
	 temp %= q;
    }
    
    if ( temp == 0 )	   d[p][m] = -1;
    else    d[p][m] = temp;
    return temp;
}

void get_Ans(){
    for ( int i = n ; i >= 1 ; i-- ){
	 ans = ans + get(i , k - 1);
	 ans %= q;
    }
}

void show_Ans(){
    cout << ans << endl;
}

void pre(int x){
    for ( int i = 1 ; i <= x ; i++ )
	 if ( int(x / i) * i == x )  vec[x].push_back(i);
}

void init(){
    vec[1].push_back(1);
    for ( int i = 2 ; i <= n ; i++ )
	 pre(i);
}

int main(){
    input();
    init();
    get_Ans();
    show_Ans();
    return 0;
}