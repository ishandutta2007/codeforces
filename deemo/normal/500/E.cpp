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

typedef long long ll;
const ll max_n = 2 * 1e5 + 100;
vector<pair<ll , ll>>  vec;
ll arr[max_n];
ll N[max_n] , R[max_n];
pair<ll , ll>	  ST[max_n][21];
int n , q , a , b;

void input(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 scanf("%d" , &a);
	 scanf("%d" , &b);
	 arr[i] = a + b;
	 vec.push_back({a , b});
    }
    cin >> q;
}

void init(){
    ll maxi , ind;
    stack<pair<int , int>>	st;//first-> index, second-> max R[i];
    for (int i = n - 1 ; i >= 0 ; i--){
	 maxi = arr[i];
	 ind = -1;
	 while (!st.empty() && vec[st.top().first].first <= arr[i]){
	     if (maxi <= st.top().second){
		  maxi = st.top().second;
		  ind = st.top().first;
	     }
	     st.pop();
	 }
	 R[i] = maxi;
	 if (ind != -1)  N[i] = N[ind];
	 else	  if(st.empty())  N[i] = -1;
	 else	  N[i] = st.top().first;
	 st.push({i , R[i]});
    }

    for (int i = 0 ; 1 << i < n ; i++)
	 for (int j = 0 ; j < n ; j++){
	     ST[j][i] = {0 , 0};
	     if (i == 0){//first-> hazineh,  second-> baadi
		  if (N[j] < 0)  ST[j][i] = {0 , -1};
		  else	   ST[j][i] = {vec[N[j]].first - R[j] , N[j]};
		  continue;
	     }
	     if (ST[j][i - 1].second == 0)	  continue;
	     if (ST[ST[j][i - 1].second][i - 1].second == 0)   continue;
	     ST[j][i] = {ST[j][i - 1].first + ST[ST[j][i - 1].second][i - 1].first , ST[ST[j][i - 1].second][i - 1].second};
	 }
}

int main(){
    input();
    init();
    for (int i = 0 ; i < q ; i++){
	 cin >> a >> b;  a--;    b--;
	 int log = log2(b - a);
	 int ans = 0;
	 while (a < b){
	     if (R[a] >= vec[b].first)   break;
	     if (ST[a][log].second <= 0 || ST[a][log].second > b){
		  log--;
		  continue;
	     }
	     
	     if (ST[a][log].second <= b) ans += ST[a][log].first;
	     a = ST[a][log].second;
	 }
	 printf("%d\n" , int(ans));
    }
    return 0;
}