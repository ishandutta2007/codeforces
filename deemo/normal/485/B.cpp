#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int N;
vector< pair<int,int> >	vec;


int main(){

	cin >> N;
	pair<int,int> temp;
	cin >> temp.first >> temp.second;
	int minx = temp.first;
	int miny = temp.second;
	int maxx = temp.first;
	int maxy = temp.second;
	for ( int i = 0 ; i < N - 1 ; i++ ){
		cin >> temp.first >> temp.second;
		if ( temp.first > maxx )	maxx = temp.first;
		if ( temp.first < minx )	minx = temp.first;
		if ( temp.second > maxy )	maxy = temp.second;
		if ( temp.second < miny )	miny = temp.second;

	}
	
	long long ans = max( maxx - minx , maxy - miny );
	if ( ans == 0 )	ans = 1;
	ans = ans * ans;
	cout << ans << endl;


	return 0;
}