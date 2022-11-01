#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	map<char,int> m;
	string s, t, u;
	map<char,int>::iterator it;
	
	cin >> s >> t;
	u.reserve( s.length() + 2 );
	for( int i = 0; i < s.length(); ++i )
		++m[ s[i] ];
	
	for( int i = 0; i < t.length(); ++i ){
		it = m.lower_bound( t[i] );
		if( it == m.end() ){
			while( !u.empty() ){
				int n = u.length() - 1;
				++m[ u[n] ];
				u.erase( n );

				it = m.upper_bound( t[--i] );
				if( it != m.end() ){
					u += it->first;
					if( !--it->second ){
						m.erase( it );
					}
					break;
				}
			}
			break;
		}
		char c = it->first;
		u += c;
		if( !--it->second ){
			m.erase( it );
			if( m.empty() ) break;
		}

		if( c > t[i] ) break;
	}

	if( !m.empty() ){
		for( it = m.begin(); it != m.end(); ++it ){
			while( it->second -- )
				u += it->first;
		}
	}

	if( t >= u ){
		next_permutation( u.begin(), u.end() );
	}

	if( t < u ){
		cout << u << '\n';
	}
	else{
		cout << "-1\n";
	}
}