#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<string>

using namespace std;

int n , m;
int mark[20];
vector<int> vec;

void create(int x , int c){
    mark[x % 10] = 1;
    if ( c == n ){
	 vec.push_back(x);
	 mark[x % 10] = 0;
	 return;
    }

    for ( int i = 1 ; i <= n ; i++ ){
	 if ( mark[i] == 0 )
	     create(x * 10 + i , c + 1);
    }
	 
    mark[x % 10] = 0;
}   

void generate(){
    for ( int i = 1 ; i <= n ; i++ )
	 create(i , 1);
}

int get_value(int x){
    int mini , temp , sum = 0;
    for ( int i = 1 ; i <= n ; i++ ){
	 for ( int j = i ; j <= n ; j++ ){
	     mini = -1;
	     for ( int k = i ; k <= j ; k++ ){
		  temp = int(x / pow(10 , (n - k))) % 10;
		  if ( mini == -1 || mini > temp )	   mini = temp;
	     }
	     sum += mini;

	 }
    }
    return sum;
}

vector< pair<int , int> >	sec;

bool help(pair<int , int> a , pair<int , int> b){
    if ( a.second < b.second )  return true;
    if ( a.second == b.second && a.first > b.first )	return true;
    return false;
}

void check_value(){
    int temp;
    for ( int i = 0 ; i < vec.size() ; i++ ){
	 temp = get_value(vec[i]);
	 sec.push_back( make_pair(vec[i] , temp) );
    }
    sort(sec.begin() , sec.end() , help);
}

void show(int x){
    vector<int> temp;
    while( x != 0 ){
	 int t = x % 10;
	 temp.push_back(t);
	 x /= 10;
    }
    reverse(temp.begin() , temp.end());

    for ( int i = 0 ; i < temp.size() - 1 ; i++ )
	 cout << temp[i] << " ";
    cout << temp[temp.size() - 1] << endl;
}   

int main(){
    cin >> n >> m;
    generate();
    check_value();
    reverse(sec.begin() , sec.end());
    show(sec[m - 1].first);
    return 0;
}