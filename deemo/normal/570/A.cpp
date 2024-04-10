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

int n , m , temp;
const int max_n = 300;
int cnt[max_n];

int main(){
    read_fast;
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++){
	 int mini = -1 , ind;
	 for (int j = 0 ; j < n ; j++){
	     cin >> temp;
	     if (mini == -1 || mini < temp){
		  mini = temp;
		  ind = j;
	     }
	 }
	 cnt[ind] += 1;
    }
    int mini = -1 , ind;
    for (int i = 0 ; i < 200 ; i++){
	 if (mini == -1 || mini < cnt[i]){
	   ind = i;
	     mini = cnt[i];
	 }
    }
    cout << ind + 1 << endl;
    return 0;
}