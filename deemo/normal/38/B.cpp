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

int jad[200][200];

int main(){
    char c1 , c2;
    int a1 , a2;
    cin >> c1 >> a1;
    int b1 = int(c1) - 96;
    cin >> c2 >> a2;
    int b2 = int(c2) - 96;
    a1++;   a2++;   b1++;	b2++;
    for (int i = 0 ; i < 100 ; i++)
	 jad[a1][i] = 1;
    for (int i = 0 ; i < 100 ; i++)
	 jad[i][b1] = 1;
    
    jad[a2][b2] = 1;
    jad[a2 + 1][b2 + 2] = 1;
    jad[a2 + 1][b2 - 2] = 1;
    jad[a2 - 1][b2 + 2] = 1;
    jad[a2 - 1][b2 - 2] = 1;
    jad[a2 + 2][b2 + 1] = 1;
    jad[a2 + 2][b2 - 1] = 1;
    jad[a2 - 2][b2 + 1] = 1;
    jad[a2 - 2][b2 - 1] = 1;
    jad[a2][b2] = 2;
    jad[a1][b1] = 2;
    jad[a1 + 1][b1 + 2] = 1;
    jad[a1 + 1][b1 - 2] = 1;
    jad[a1 - 1][b1 + 2] = 1;
    jad[a1 - 1][b1 - 2] = 1;
    jad[a1 + 2][b1 + 1] = 1;
    jad[a1 + 2][b1 - 1] = 1;
    jad[a1 - 2][b1 + 1] = 1;
    jad[a1 - 2][b1 - 1] = 1;

    int ans = 0;
    for (int i = 2 ; i < 10 ; i++)
	 for (int j = 2 ; j < 10 ; j++){
	     if (jad[i][j])	continue;
	     ans++;
	 }
    cout << ans << endl;

    return 0;
}