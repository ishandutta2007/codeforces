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

int n , mini = 1e9 , ans;
vector<int> vec , sec;
const int max_n = 2 * 1e5;
stack<int>  st[max_n];

int cnt(int x){
    int ret = 0;
    while (x > 0){
	 if (x & 1)  ret++;
	 x >>= 1;
    }
    return  ret;
}

int dec(int x , int y){
    if (y == mini)  return	x;
    while (x > 0){
	 if (x & 1)  y--;
	 x >>= 1;
	 ans++;
	 if (y == mini)  return  x;
    }
    return  x;
}

void get(int x , int ind){
    bool flag = 0;
    int t = 0;
    while (x > 0){
	 if (x & 1){
	     if (flag == 1)	st[ind].push(t);
	     flag = 1;
	     t = 0;
	 }
	 t++;
	 x >>= 1;
    }
}

int cal(int x , int y){
    int cnt = 0;
    while (x > 0){
	 x >>= 1;
	 cnt++;
    }
    return  abs(y - cnt);
}

int sec_dec(int x , int y){
    while (y > mini){
	 if (x & 1)  y--;
	 x >>= 1;
	 ans++;
    }
    return  x;
}

int main(){
    cin >> n;
    int temp;	  
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.push_back(temp);
	 sec.push_back(cnt(temp));
	 mini = min(mini , sec[i]);
    }
    for (int i = 0 ; i < n ; i++){
	 if (sec[i] > mini){
	     vec[i] = dec(vec[i] , sec[i]);
	     sec[i] = mini;
	 }
	 get(vec[i] , i);
    }
    
    int c = 0;
    for (int i = 0 ; i < mini - 1 ; i++){
	 bool flag = 0;
	 temp = st[0].top();
	 st[0].pop();
	 for (int j = 1 ; j < n ; j++){
	     if (st[j].top() != temp)	 flag = 1;
	     st[j].pop();
	 }
	 if (flag)   break;
	 c++;
    }
    mini = c + 1;
    for (int i = 0 ; i < n ; i++)
	 vec[i] = sec_dec(vec[i] , sec[i]);
    
    mini = 1e9;
    for (int i = 1 ; i < 30 ; i++){
	 temp = 0;
	 for (int j = 0 ; j < n ; j++)
	     temp += cal(vec[j] , i);
	 if (mini > temp)	mini = temp;
    }
    ans += mini;
    cout << ans << endl;
    return 0;
}