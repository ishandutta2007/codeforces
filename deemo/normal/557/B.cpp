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

using namespace std;

int n , w;
vector<int> vec;

int main(){
    cin >> n >> w;
    int temp;
    for (int i = 0 ; i < 2 * n ; i++){
	 cin >> temp;
	 vec.push_back(temp);
    }
    sort(vec.begin() , vec.end());
    int mini = vec[0] , maxi = vec[n];
    double ans = double(maxi) / double(2);
    if (ans > mini) ans = mini;
    if (ans > double(w / double(3 * n)))	  ans = double(w / double(3 * n));
    cout<<fixed << setprecision(7);
    ans = double( double(double(ans * n) * 3));
    cout << ans << endl;
    return 0;
}