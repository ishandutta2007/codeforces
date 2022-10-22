#include<iostream>
#include<vector>
#include<set>

using namespace std;

int n , x_0 , y_0;
const int max_n = 1000 + 10;
int x[max_n];
int y[max_n];
set<long double> save;
int mark[max_n];

void input(){
    cin >> n >> x_0 >> y_0;

    for ( int i = 0 ; i < n ; i++ )
	 cin >> x[i] >> y[i];
}

int ans;
int fl;

void get_Ans(){
    long double m;
    for ( int i = 0 ; i < n ; i++ ){
	 if ( mark[i] == 1 )	continue;
	 if ( x[i] == x_0 ){
	     fl = 1;
	     mark[i] = 1;
	     continue;
	 }

	 if ( x_0 > x[i] )	m = (y_0 - y[i]) / double(x_0 - x[i]);
	 else	  m = (y[i] - y_0) / double(x[i] - x_0);
	 
	 save.insert(m);	 
	 mark[i] = 1;
    }
}

int main(){
    input();
    get_Ans();
    cout << fl + save.size() << endl;
    return 0;	  
}