#include<vector>
#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

long long int ans;
long long int n , r , avg;
vector< pair<int , int> >	exams;	


bool help( pair<long long int , long long int> a , pair<long long int , long long int> b ){
	if ( a.second < b.second )	return true;
	if ( ( a.second == b.second ) && ( a.first < b.first ) )	return true;
	return false;

}


int main(){
	
	cin >> n >> r >> avg;
	{
		pair<long long int , long long int>	temp;
		for ( long long int i = 0 ; i < n ; i++ ){
			cin >> temp.first >> temp.second;
			exams.push_back(temp);

		}
		sort( exams.begin() , exams.end() , help );

	}

	long long int x = avg * n;
	long long int sum = 0;
	for ( int i = 0 ; i < n ; i++ )
		sum += exams[i].first;
	x = x - sum;
	if ( x <= 0 )	cout << 0 << endl;
	else{	
		long long int temp;
		for ( long long int i = 0 ; i < n ; i++ ){
			temp = r - exams[i].first;
			if ( r - exams[i].first >= x ){
				ans += x * exams[i].second;
				break;
			
			}
			ans += temp * exams[i].second;
			x -= temp;

		}
		cout << ans << endl;

	}		

	return 0;

}