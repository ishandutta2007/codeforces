#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>
#include<utility>

using namespace std;

long long int n , maxi;
long long int a[10000];
long long int d[10000];
long long int z[10000];
long long int ans;

void input(){
    cin >> n;
    n += 1;
    for ( long long int i = 2 ; i < pow(2 , n) ; i++ )
	 cin >> a[i];
}

long long int get(long long int v){
    if ( d[v] != 0 )	   return d[v];

    if ( v == 2 || v == 3 ){
	 d[v] = a[v];
	 return  d[v];
    }
    return d[ int(v / 2) ] + a[v];
}

long long int get_max(long long int v){
    if ( z[v] != 0 )	   return z[v];

    if ( v >= pow(2 , n) )
	 return  0;
    z[v] = max(get_max(v * 2) + a[v * 2] , get_max(v * 2 + 1) + a[v * 2 + 1]); 
    return z[v];
}

void get_lights(){
    for ( long long int i = 2 ; i < pow(2 , n) ; i++ ){
	 d[i] = get(i);
	 if ( i >= pow(2 , n - 1) && (maxi == -1 || maxi < d[i]) )
	     maxi = d[i];

	 z[i] = get_max(i);
    }

}   

void get_Ans(long long int g , long long int t){
    if ( g >= pow(2 , n) )	return;

    ans += maxi - z[g * 2] - a[g * 2] - t;
    long long int temp = t;
    a[g * 2] += maxi - z[g * 2] - a[g * 2] - t;
    t += a[g * 2];
    get_Ans(g * 2 , t);

    ans += maxi - z[g * 2 + 1] - a[g * 2 + 1] - temp;
    a[g * 2 + 1] += maxi - z[g * 2 + 1] - a[g * 2 + 1] - temp;
    temp += a[g * 2 + 1];
    get_Ans(g * 2 + 1 , temp);
}

int main(){
    input();
    get_lights();
    get_Ans(1 , 0);
    cout << ans << endl;
    return 0;
}