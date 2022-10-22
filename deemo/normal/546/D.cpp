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

const int max_n = 5 * 1e6 + 100;
long long p[max_n];
long long c[max_n] , d[max_n];
int t , a , b;

int get(int x){
    if (c[x])	  return  1;
    int ret = 0;
    if (x % 2 == 0) return	d[x / 2] + 1;
    for (int i = 3 ; i <= sqrt(x) ; i += 2){
	 if (x % i != 0) continue;
	 return  d[x / i] + 1;
    }
    return ret;
}

bool pr(int x){
    if (x % 2 == 0) return	false;
    for (int i = 3 ; i <= sqrt(x) ; i+=2)
	 if (x % i == 0) return  false;
    return true;
}

void init(){
    d[1] = 0;
    d[2] = d[3] = 1;
    c[1] = 0;	  c[2] = c[3] = 1;
    for (int i = 4 ; i <= 5 * 1e6 ; i++)
	 c[i] = pr(i);

    for (int i = 4 ; i <= 5 * 1e6 ; i++){
	 d[i] = get(i);
    }

    for (int i = 1 ; i <= 5 * 1e6 ; i++){
	 if (i == 1) p[i] = d[i];
	 else	  p[i] = d[i] + p[i - 1];
    }
	 
}

int main(){
    init(); 
    cin >> t;
    for (int i = 0 ; i < t ; i++){
	 scanf("%d" , &a);
	 scanf("%d" , &b);
	 int ans = p[a] - p[b];
	 printf("%d\n" , ans);
    }	
    return 0;
}