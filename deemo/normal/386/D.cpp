/*
    I found myself in Wonderland
    Get back on my feet again..
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
#include<numeric>

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;

struct Pos{
    int a[3];
    Pos(){};
    Pos(int a , int b , int c){
	 this->a[0] = a , this->a[1] = b , this->a[2] = c;
    }
};

bool operator < (Pos a , Pos b){
    if (a.a[0] < b.a[0])	return	 true;
    if (a.a[0] > b.a[0])	return	 false;
    if (a.a[1] < b.a[1])	return	 true;
    if (a.a[1] > b.a[1])	return	 false;
    if (a.a[2] < b.a[2])	return	 true;
    return  false;
}

int n;
char col[100][100];
map<Pos , Pos>  par;
bool mark[100][100][100];
Pos saved;

void bfs(Pos s){
    deque<Pos>  saf;
    saf.push_back(s);
    mark[s.a[0]][s.a[1]][s.a[2]] = 1;
    par[s] = Pos(-1 , -1 , -1);

    while (!saf.empty()){
	 Pos t = saf.front();
	 saf.pop_front();
	 for (int i = 0 ; i < 3 ; i++)
	     for (int j = 0 ; j < n ; j++){
		  if (j == t.a[i])	 continue;
		  int a = -1 , b = -1;
		  bool flag = 0;
		  for (int p = 0 ; p < 3 ; p++){
		      if (p == i) continue;
		      if (a == -1)	 a = p;
		      else	b = p;
		      if (t.a[p] == j)    flag = 1;
		  }
		  if (flag)	continue;
		  if (col[t.a[i]][j] != col[t.a[a]][t.a[b]])	   continue;	 
		  Pos temp = t;
		  t.a[i] = j;
		  if (mark[t.a[0]][t.a[1]][t.a[2]]){
		      t = temp;
		      continue;
		  }
		  mark[t.a[0]][t.a[1]][t.a[2]] = 1;
		  par[t] = temp;
		  saf.push_back(t);
		  if (t.a[0] < 3 && t.a[1] < 3 && t.a[2] < 3 && saved.a[0] == -1){
		      saved = t;
		      return;
		  }
		  t = temp;
	     }
    }
}

int z;

void show_path(Pos v){
    z++;
    if (par[v].a[0] == -1){
	 cout << z - 1 << endl;
    	 return;
    }
    show_path(par[v]);
    Pos t = par[v];
    for (int i = 0 ; i < 3 ; i++)
	 if (t.a[i] != v.a[i])   cout << t.a[i] + 1 << " " << v.a[i] + 1 << endl;
}

int main(){
    read_fast;
    cin >> n;
    Pos start;
    saved = Pos(-1 , -1 , -1);
    int a , b , c;
	 cin >> a >> b >> c;
	 a--;	  b--;	   c--;
	 start = Pos(a , b , c);
	 for (int i = 0 ; i < n ; i++)
	     for (int j = 0 ; j < n ; j++)
		  cin >> col[i][j];
    if (a < 3 && b < 3 && c < 3){
	 cout << 0 << endl;
	 return  0;
    }
    bfs(start);
    if (saved.a[0] == -1){
	 cout << -1 << endl;
	 return  0;
    }
    show_path(saved);
    saved = Pos(1 , 7 , 0);
    return 0;
}