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

int m , w;
vector<long long>   vec;
map<long long,bool> mp;

long long get(long long x){
    long long ret = 0 , t = 1;
    while (x > 0){
	 if (x & 1)  ret += t;
	 t *= w;
	 x >>= 1;
    }
    return  ret;
}

int main(){
    cin >> w >> m;
    if (w == 2){
	 cout << "YES" << endl;
	 return  0;
    }	 

    long long q = 1 , sum = 1;
    while (1){
	 q *= w;
	 if (q > m + sum)	break;
	 sum += q;
    }
    long long t = 0;
    for (long long int i = 0 ; (t = get(i)) < q ; i++){
	 vec.push_back(t); 
	 mp[t] = 1;
    }	 
    mp[0] = 1;

    for (int i = 0 ; i < vec.size() ; i++){
	 t = vec[i];
	 long long c;
	 if (t >= m){
	     c = t - m;
	     if (mp[c] == 1){
		  cout << "YES" << endl;
		  return  0;
	     }
	 }
    }
    cout << "NO" << endl;
    return 0;
}