#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<utility>
#include<iomanip>
#include<stack>
#include<cstdio>

using namespace std;

int n , k , p , x , y;
int temp , sum , cnt;
vector<int> ans;

int main(){
    cin >> n >> k >> p >> x >> y;
    for (int i = 1 ; i <= k ; i++){
	 cin >> temp;
	 sum += temp;
	 if (temp >= y) cnt++;
    }

    while (cnt <= n / 2 && k < n){
	 k++;
	 ans.push_back(y);
	 cnt++;
	 sum += y;
    }
    
    if (cnt <= n / 2){
	 cout << -1 << endl;
	 return 0;
    }

    sum += n - k;
    for (int i = k ; i < n ; i++)
	 ans.push_back(1);

    if (sum > x){
	 cout << -1 << endl;
	 return 0;
    }	 

    for (int i = 0 ; i < ans.size() - 1 ; i++)
	 cout << ans[i] << " ";
    cout << ans[ans.size() - 1] << endl;
   
    return 0;
}