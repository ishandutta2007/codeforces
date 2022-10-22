#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

long long int n , q , b;
const int max_n = 1000 * 1000 + 10;
vector<int> vec;
int t[max_n];
int s[max_n];
int p[max_n];
int maxi = -1 , ind;

void input(){
    cin >> n >> q;
    int temp;
    
    for ( int i = 0 ; i < n ; i++ ){
	 scanf("%d" , &temp);
	 vec.push_back(temp);

	 if ( i == 0 )   p[i] = vec[i];
	 else	  p[i] = p[i - 1] + vec[i];
    }
}

void get_min(){
    int j = 0;
    for ( int i = 0 ; i < n ; i++ ){
	  while ( t[i] + vec[j] <= b ){
	     t[i] += vec[j];
	     s[i] += 1;
	     j = (j + 1) % n;
	     if ( j == i )	break;
	 }

	 if ( i != n - 1 ){
	     t[i + 1] = t[i] - vec[i];
	     s[i + 1] = s[i] - 1;
	 }   
    }

    for ( int i = 0 ; i < n ; i++ ){
	 if ( s[i] < maxi || maxi == -1 ){
	     maxi = s[i];
	     ind = i;	   
	 }
    }
}

int par(int j , int i){
    if ( i == j )   return vec[i];
    
    if ( i > j ){
	 if ( j == 0 )   return p[i];
	 else	  return p[i] - p[j - 1];
    }
    
    return p[i] + (p[n - 1] - p[j - 1]);
}

int get(int first){
    int ret = 0 , op = 0;

    while ( op < n ){
	 first = (first + s[first]) % n;
	 op += s[first];	 
	 ret += 1;
    }
	 
    return ret;
}

int ans;

void get_Ans(){
    get_min();
    ans = -1;	  

    int first , temp;
    for ( int i = 0 ; i <= maxi ; i++ ){
	 first = (ind + i) % n;  
	 temp = get(first);
	 
	 if ( temp < ans || ans == -1 )  ans = temp;
    }
}

void clear(){
    for ( int i = 0 ; i < n ; i++ )
	 t[i] = s[i] = 0;
    maxi = -1;
    ind = 0;
}

int main(){
    input();
    for ( int i = 0 ; i < q ; i++ ){
	 cin >> b;
	 get_Ans();
	 cout << ans << endl;
	 clear();
    }	 
    return 0;
}