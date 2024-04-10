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

typedef long long ll;
string s;
ll odd , even;
ll aeven , aodd , beven , bodd;

int main(){
    cin >> s;
    odd = 1;
    if (s[0] == 'a')	   aeven += 1;
    else    beven += 1;
    for (int i = 1 ; i < s.size() ; i++){
	 if (s[i] == 'a'){
	     if (i % 2 == 0)	aeven++;
	     else    aodd++;
	     if (i % 2 == 0)	odd += aeven , even += aodd;
	     else    odd += aodd , even += aeven;
	 }
	 if (s[i] == 'b'){
	     if (i % 2 == 0)	beven++;
	     else    bodd++;
	     if (i % 2 == 0)	odd += beven , even += bodd;
	     else    odd += bodd , even += beven;
	 }
    }
    cout << even << " " << odd << endl;
    return 0;
}