/*
    God save us everyone 
    will we burn inside the fires of a thousand suns?
    for the sins of our hands 
    the sins of our tongues
    the sins of our fathers
    the sins of our young..
*/

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
#include<cstring>
#include<bitset>
#include<functional>

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;

struct State{
    int x , y;
    bool turn;
    void set(int a , int b , bool c){
	 x = a  , y = b , turn = c;
    }
};

int n , m;
const int max_n = 600;
vector<int> ad_list[max_n];
State par[max_n][max_n][3];
bool mark[max_n][max_n][3] , flag;
int depth[max_n][max_n][3];

void bfs(State s){
    deque<State>    deq;
    deq.pb(s);
    mark[s.x][s.y][s.turn] = 1;
    while (!deq.empty()){
	 State t = deq.front();
	 deq.pop_front();
	 if (!t.turn == 0)
	     for (int i = 0 ; i < ad_list[t.x].size() ; i++){
		  State temp;
		  temp.set(ad_list[t.x][i] , t.y , !t.turn);
		  if (mark[temp.x][temp.y][temp.turn])	continue;
		  mark[temp.x][temp.y][temp.turn] = 1;
		  depth[temp.x][temp.y][temp.turn] = depth[t.x][t.y][t.turn] + 1;
		  deq.pb(temp);
		  par[temp.x][temp.y][temp.turn] = t;
	     }
	 else{
	     for (int i = 0 ; i < ad_list[t.y].size() ; i++){
		  State temp;
		  temp.set(t.x , ad_list[t.y][i] , !t.turn);
		  if (mark[temp.x][temp.y][temp.turn])	continue;
		  if (temp.x == temp.y)   continue;
		  mark[temp.x][temp.y][temp.turn] = 1;
		  depth[temp.x][temp.y][temp.turn] = depth[t.x][t.y][t.turn];
		  deq.pb(temp);
		  par[temp.x][temp.y][temp.turn] = t;
		  if (temp.x == n - 1 && temp.y == 0) flag = 1;
	     }
	 }
    }
}

queue<int>  saf;
void show_path(State v){
    if (v.x == 0 && v.y == n - 1 && v.turn == 1){
	 cout << v.x + 1 << " ";
	 return;
    }
    show_path(par[v.x][v.y][v.turn]);
    if (v.turn == 1)	   cout << v.x + 1 << " ";
    else    saf.push(v.y + 1);
}

int main(){
    read_fast;
    cin >> n >> m;
    {
	 int a , b;
	 for (int i = 0 ; i < m ; i++){
	     cin >> a >> b;
	     a--;    b--;
	     ad_list[a].pb(b);
	     ad_list[b].pb(a);
	 }
    }
    State temp;
    temp.set(0 , n - 1 , 1);
    bfs(temp);
    if (!flag){
	 cout << -1 << endl;
	 return  0;
    }
    cout << depth[n - 1][0][1] << endl;
    temp.set(n - 1 , 0 , 1);
    show_path(temp);
    cout << endl;
    while (!saf.empty()){
	 cout << saf.front() << " ";
	 saf.pop();
    }
    cout << 1 << endl;
    return 0;
}