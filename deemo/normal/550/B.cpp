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

vector<int> sec , vec , fec;
vector<vector<int>> gec;
int ans;
int n , temp , x , l , r;

void generate(int ind , vector<int> temp , int sum){
    if (ind == n - 1){
	 gec.push_back(temp);
	 fec.push_back(sum);
	 temp.push_back(ind);
	 sum += vec[ind];
	 gec.push_back(temp);
	 fec.push_back(sum);
	 temp.pop_back();
	 sum -= vec[ind];
	 return;
    }
    generate(ind + 1 , temp , sum);
    temp.push_back(ind);
    sum += vec[ind];
    generate(ind + 1 , temp , sum);
    temp.pop_back();
    sum -= vec[ind];
}   

int main(){
    cin >> n >> l >> r >> x;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.push_back(temp);
    }
    sort(vec.begin() , vec.end());
    generate(0 , sec , 0);

    for (int i = 0 ; i < gec.size() ; i++){
	 if (gec[i].size() < 2)  continue;
	 if (fec[i] < l) continue;
	 if (fec[i] > r) continue;
	 if (vec[gec[i][gec[i].size() - 1]] - vec[gec[i][0]] < x)	continue;
	 ans++;
    }
    cout << ans << endl;

    return 0;
}