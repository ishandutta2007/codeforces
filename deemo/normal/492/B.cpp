#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n , l;
vector<int>	lanterns;
double ans;

int main(){
	
	cin >> n >> l;
	{
		int temp;
		for ( int i = 0 ; i < n ; i++ ){
			cin >> temp;
			lanterns.push_back(temp);

		}
		sort( lanterns.begin() , lanterns.end() );
		lanterns.push_back(-100);

	}

	int i = lanterns[0] , index = 1;
	double temp;
	ans = lanterns[0];
	while ( index < n ){
		if ( lanterns[index] != lanterns[index + 1] ){
			temp = lanterns[index] - i;
			temp = temp / 2;
			ans = max( temp , ans );
			i = lanterns[index];

		}
		index++;

	}
	if ( l - lanterns[n - 1] > ans )	ans = l - lanterns[n - 1];
	cout.precision(11);
	cout << ans << endl;
	
	return 0;

}