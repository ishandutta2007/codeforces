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

int k , l , m , n , d;
int ans;
const int max_n = 1e5 + 100;
bool mark[max_n];

void f(int x){
    int i = x;
    while (i <= d){
	 if (mark[i] == 0)	ans++;
	 mark[i] = 1;
	 i += x;
    }
}

int main(){
    cin >> k >> l >> m >> n >> d;
    
    f(k);
    f(l);
    f(m);
    f(n);
    cout << ans << endl;

    return 0;
}