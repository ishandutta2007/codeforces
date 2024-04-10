#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>
#include<fstream>
#include<list>
#include<sstream> 

using namespace std;

typedef long long ll;
#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb(x) push_back((x))
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)

int main(){
    int n , temp;
    cin >> n;
    vector<int> vec;
    for (int i = 0 ; i < n ; i++){
        cin >> temp;
        vec.pb(temp);
    }
    sort(vec.begin() , vec.end());
    if (vec[0] == 1)  cout << -1 << endl;
    else    cout << 1 << endl;
    return 0;
}