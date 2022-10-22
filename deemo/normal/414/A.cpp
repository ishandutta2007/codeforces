#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>

using namespace std;

int n , k;
set<int>    dis;

void input(){
    cin >> n >> k;
}

bool is_bad(){
    if ( n / 2 > k )	   return true;
    if ( n == 1 && k != 0 )	return true;
    return false;
}

int find(){
    for ( int i = 1000 * 100 * 4 ; i > 0 ; i++ )
	 if ( dis.find(i) == dis.end() ) return i;
    return -1;
}

void init(){
    int temp = k - ( (n - 2) / 2 );
    if ( n == 2 )   
	 cout << 2 * temp << " " << 1 * temp << endl;
    else    if ( n == 3 )
	 cout << 2 * temp << " " << 1 * temp << " " << find() << endl;
    else    cout << 2 * temp << " " << 1 * temp << " ";
    dis.insert(1 * temp);
    dis.insert(2 * temp);
    n -= 2;
}

bool is_good(int g){
    if ( dis.find(g) == dis.end() && dis.find(g + 1) == dis.end() ) return true;
    return false;
}   

void get_Ans(){
    init();

    int g = 1;
    for ( int i = 0 ; i < n / 2 ; i++ ){
	 while ( !is_good(g) )   g++;
	 dis.insert(g);
	 dis.insert(g + 1);
	 if ( i == (n / 2) - 1 && n % 2 == 0 )   cout << g << " " << g + 1 << endl;
	 else	  if ( i == (n / 2) - 1 && n % 2 == 1 )	cout << g << " " << g + 1 << " " << find() << endl;
	 else	  cout << g << " " << g + 1 << " ";
	 g += 2;
    }
}

int main(){
    input();
    if ( is_bad() ){
	 cout << -1 << endl;
	 return 0;
    }
    if ( n == 1 && k == 0 ){
	 cout << 5 << endl;
	 return 0;
    }
    
    get_Ans();
    return 0;	  
}