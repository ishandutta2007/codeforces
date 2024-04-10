#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n , m;
const int max_n = 500 + 10;
vector<int> w;
int mark[max_n];
vector<int> vec;
vector<int> sec;
int ind[max_n];

void input(){
    cin >> n >> m;
    int temp;
    for ( int i = 0 ; i < n ; i++ ){
	 cin >> temp;
	 w.push_back(temp);
    }

    for ( int i = 0 ; i < m ; i++ ){
	 cin >> temp;
	 sec.push_back(temp);
	 if ( mark[temp] != 0 )	continue;
	 vec.push_back(temp);
	 mark[temp] = 1;
    }

    reverse(vec.begin() , vec.end());
    for ( int i = 0 ; i < vec.size() ; i++ )
	 ind[vec[i]] = i + 1;
}

long long int ans;

void pick(int v){
    for ( int i = 1 ; i <= n ; i++ ){
	 if ( i == v )   continue;
	 if ( ind[i] > ind[v] ){
	     ind[i] -= 1;
	     ans += w[i - 1];
	 }
    }
    ind[v] = n;
}

void get_Ans(){
    for ( int i = 0 ; i < sec.size() ; i++ )
	 pick(sec[i]);
}

int main(){
    input();
    get_Ans();
    cout << ans << endl;
    return 0;
}