#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n , m;
int boys[100 + 5];
int girls[100 + 5];


int main(){
	
	cin >> n;
	int temp;
	for ( int i = 0 ; i < n ; i++ ){

		cin >> temp;
		boys[temp] += 1;

	}

	cin >> m;
	for ( int j = 0 ; j < m ; j++ ){

		cin >> temp;
		girls[temp] += 1;

	}

	int ans = 0;
	if ( n <= m ){

		for ( int i = 0 ; i <= 100 ; i++ ){

			while( boys[i] > 0 ){

				if ( girls[i - 1] > 0 ){

					ans++;
					boys[i] -= 1;
					girls[i - 1] -= 1;
	
				}
				else if ( girls[i] > 0 ){
			
					ans++;
					boys[i] -= 1;
					girls[i] -= 1;			

				}
				else if ( girls[i + 1] > 0 ){

					ans++;
					boys[i] -= 1;
					girls[i + 1] -= 1;

				}
				else break;

			}

		}

	}
	else{

		for ( int i = 0 ; i <= 100 ; i++ ){

			while( girls[i] > 0 ){

				if ( boys[i - 1] > 0 ){

					ans++;
					girls[i] -= 1;
					boys[i - 1] -= 1;

				}
				else if ( boys[i] > 0 ){

					ans++;
					boys[i] -= 1;
					girls[i] -= 1;

				}
				else if ( boys[i + 1] > 0 ){

					ans++;	
					boys[i + 1] -= 1;
					girls[i] -= 1;	

				}
				else break;

			}
	

		}
		

	}
	
	cout << ans << endl;
	return 0;

}