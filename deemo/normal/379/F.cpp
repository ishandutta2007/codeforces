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

const int max_n = 15 * 1e5 + 10;
const int max_lg = 30;
int L[max_n];
int T[max_n];
int P[max_n][max_lg];
int m , n , ta , tb , da , db , diameter , x;

void init(){
    diameter = 2;
    da = 2;	  db = 3;
    T[1] = -1;
    L[1] = 1;
    for (int i = 2 ; i <= 4 ; i++)
	 T[i] = 1 , L[i] = L[1] + 1;
    n = 4;

    for (int i = 1 ; i <= 4 ; i++)
	 P[i][0] = T[i];
}

void update(int v){
    P[v][0] = T[v];
    for (int i = 1 ; 1 << i <= L[v] - 1 ; i++)
	 if (P[v][i - 1] > 0) 
	     P[v][i] = P[P[v][i - 1]][i - 1];
}

int lca(int u , int v){
    if (L[u] < L[v])	   swap(u , v);//v bala tare
    int log;
    for (log = 1 ; 1 << log <= L[u] ; log++);
    log--;
    
    for (int i = log ; i >= 0 ; i--)
	 if (L[u] - (1 << i) >= L[v])
	     u = P[u][i];
    if (u == v) return  v;

    for (int i = log ; i >= 0 ; i--)
	 if (P[u][i] != -1 && P[u][i] != P[v][i])
	     u = P[u][i] , v = P[v][i];
    return  T[u];

}

int main(){
    init();
    scanf("%d" , &m);
    for (int i = 0 ; i < m ; i++){
	 scanf("%d" , &x);
	 T[n + 1] = T[n + 2] = x;
	 L[n + 1] = L[n + 2] = L[x] + 1;
	 update(n + 1);	update(n + 2);
	 ta = lca(da , n + 1);	 tb = lca(db , n + 1);	
	 if (abs(L[ta] - L[n + 1]) + abs(L[ta] - L[da]) > diameter){
	     diameter++;
	     db = n + 1;
	 }
	 else if (abs(L[tb] - L[n + 1]) + abs(L[tb] - L[db]) > diameter){
	     diameter++;
	     da = n + 1;
	 }
	 printf("%d\n" , diameter);
	 n += 2;
    }
    return 0;
}