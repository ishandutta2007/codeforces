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

string s1 , s2;
int sum1 , sum2 , sum11 , sum12, sum13;
int ans , all;

void get(int rem , int p , int m){
    if (rem == 0){
	 all++;
	 if (p == sum1)  ans++;
	 return;
    }
    
    get(rem - 1 , p + 1 , m);
    get(rem - 1 , p , m + 1);
}

int main(){
    cout << fixed << setprecision(12);
    cin >> s1 >> s2;
    for (int i = 0 ; i < s1.size() ; i++){
	 if (s1[i] == '+')	sum1++;
	 else	  sum2++;
    }

    for (int i = 0 ; i < s2.size() ; i++){
	 if (s2[i] == '+')	sum11++;
	 if (s2[i] == '-')	sum12++;
	 if (s2[i] == '?')	sum13++;
    }
    get(sum13 , sum11 , sum12);
    double t = ans / double(all);
    cout << t << endl;
    return 0;
}