#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<utility>

using namespace std;

int mes[300];
int news[300];
int ans1 , ans2;

int main(){
    string s1 , s2;
    cin >> s1 >> s2;
    
    for ( int i = 0 ; i < s1.size() ; i++ )
	 mes[ int(s1[i]) ] += 1;

    for ( int i = 0 ; i < s2.size() ; i++ )
	 news[ int(s2[i]) ] += 1;

    int temp;
    for ( int i = 65 ; i <= 122 ; i++ ){
	 if ( i > 90 && i < 97 ) continue;
	 ans1 += min(news[i] , mes[i]);
	 temp = min(news[i] , mes[i]);
	 news[i] -= temp;
	 mes[i] -= temp;
    }
    for ( int i = 65 ; i <= 90 ; i++ ){
	 mes[i] += mes[i + 32];
	 if ( mes[i] == 0 )	continue;
	 
	 temp = min(mes[i] , news[i] + news[i + 32] + news[i - 32]);
	 ans2 += temp;
    }

    cout << ans1 << " " << ans2 << endl;

    
	     

    return 0;
}