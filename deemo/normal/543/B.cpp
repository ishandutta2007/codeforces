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

const int max_n = 4000;
int s1 , s2 , t1 , t2 , l1 , l2 , n , m , a , b , ans , g;
int d[max_n][max_n];
int mark[max_n];
vector<int> vec[max_n];

void bfs(int v){
    d[v][v] = 0;
    g++;
    mark[v] = g;
    queue<int>  saf;
    saf.push(v);    

    int temp , ad;
    while (!saf.empty()){
	 temp = saf.front();
	 saf.pop();
	 for (int i = 0 ; i < vec[temp].size() ; i++){
	     ad = vec[temp][i];
	     if (mark[ad] == g)  continue;
	     mark[ad] = g;
	     d[v][ad] = d[v][temp] + 1;
	     saf.push(ad);
	 } 
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++){
	 cin >> a >> b;
	 a--;	  b--;
	 vec[a].push_back(b);
	 vec[b].push_back(a);
    }
    cin >> s1 >> t1 >> l1;	s1--;	 t1--;
    cin >> s2 >> t2 >> l2;	s2--;	 t2--;
    for (int i = 0 ; i < n ; i++)
	 bfs(i);
    if (d[s1][t1] > l1 || d[s2][t2] > l2){
	 cout << -1 << endl;
	 return  0;
    }
    ans = d[s1][t1] + d[s2][t2];
    for (int i = 0 ; i < n ; i++)
	 for (int j = i ; j < n ; j++){
	     int temp = d[i][j];
	     int y = min(d[j][t1] + d[i][s1] , d[j][s1] + d[i][t1]);
	     int x = min(d[j][t2] + d[i][s2] , d[j][s2] + d[i][t2]);
	     if (y + temp > l1)	continue;
	     if (x + temp > l2)	continue;
	     temp += x + y;
	     if (temp < ans)	ans = temp;
	 }    
    cout << m - ans << endl;

    return 0;
}