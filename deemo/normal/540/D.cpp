#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<utility>
#include<iomanip>
#include<stack>
#include<cstdio>

using namespace std;

int r , s , p;
const int max_n = 110;
double rd[max_n][max_n][max_n];
double sd[max_n][max_n][max_n];
double pd[max_n][max_n][max_n];
double ansr , ansp , anss;

double cala(int a , int b , int c , double t){
    if (t == 0) return 0;
    if (rd[a][b][c] != 3)	return	 t * rd[a][b][c];
    if (a == 0) return  0;
    if (a > 0 && b == 0 && c == 0)	 return t;
    
    double temp = 0;
    int g = a * b + a * c + b * c;

    temp += cala(a - 1 , b , c , a * c / double(g));
    temp += cala(a , b - 1 , c , a * b / double(g));
    temp += cala(a , b , c - 1 , b * c / double(g));
        
    rd[a][b][c] = temp;
    return  t * rd[a][b][c];
}

double calb(int a , int b , int c , double t){
    if (t == 0) return 0;
    if (sd[a][b][c] != 3)	return	 t * sd[a][b][c];
    if (b == 0) return  0;
    if (a == 0 && b > 0 && c == 0)	 return t;
    
    double temp = 0;
    int g = a * b + a * c + b * c;

    temp += calb(a - 1 , b , c , a * c / double(g));
    temp += calb(a , b - 1 , c , a * b / double(g));
    temp += calb(a , b , c - 1 , b * c / double(g));
        
    sd[a][b][c] = temp;
    return  t * sd[a][b][c];
}

double calc(int a , int b , int c , double t){
    if (t == 0) return 0;
    if (pd[a][b][c] != 3)	return	 t * pd[a][b][c];
    if (c == 0) return  0;
    if (a == 0 && b == 0 && c > 0)	 return t;
    
    double temp = 0;
    int g = a * b + a * c + b * c;

    temp += calc(a - 1 , b , c , a * c / double(g));
    temp += calc(a , b - 1 , c , a * b / double(g));
    temp += calc(a , b , c - 1 , b * c / double(g));
        
    pd[a][b][c] = temp;
    return  t * pd[a][b][c];
}

int main(){
    cout << fixed << setprecision(12);
    cin >> r >> s >> p;
    
    for (int i = 0 ; i <= r ; i++)
	 for (int j = 0 ; j <= s ; j++)
	     for (int k = 0 ; k <= p ; k++){
		  rd[i][j][k] = 3;
		  sd[i][j][k] = 3;
		  pd[i][j][k] = 3;
	     }
    
    ansr = cala(r , s , p , 1);
    anss = calb(r , s , p , 1);
    ansp = calc(r , s , p , 1);
    cout << ansr << " " << anss << " " << ansp << endl;

    return 0;
}