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

int n , m , k;
const int max_n = 100 * 1000 + 30;
vector<int> vec;
vector<int> sec;
int jad[max_n];
long long int ans;

void input(){
    cin >> n >> m >> k;
    int temp;

    for ( int i = 0 ; i < n ; i++ ){
	 cin >> temp;
	 vec.push_back(temp);
	 jad[temp] = i;
    }

    for ( int i = 0 ; i < m ; i++ ){
	 cin >> temp;
	 sec.push_back(temp);
    }
}

void get_Ans(){
    int temp;
    for ( int i = 0 ; i < sec.size() ; i++ ){
	 ans += 1;
	 temp = sec[i];
	 ans += (jad[temp] / k);//screen e temp;
	 if ( jad[temp] != 0 ){
	     jad[temp] -= 1;// jaaye temp ro midim aghab
	     jad[ vec[jad[temp]] ] += 1;
	     swap(vec[jad[temp]] , vec[jad[temp] + 1]);
	 }
    }
}

int main(){
    input();
    get_Ans();
    cout << ans << endl;
    return 0;
}