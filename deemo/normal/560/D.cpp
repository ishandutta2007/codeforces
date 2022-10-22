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

using namespace std;

typedef long long ll;
#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define push_back pb
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)

string s1 , s2;

bool check(int b , int e , int b2 , int e2){
    for (int  i = b ; i <= e ; i++)
        if (s1[i] != s2[b2 + (i - b)]) return  false;
    return  true;
}

bool ok(int b , int e , int b2 , int e2){
    if ((e - b + 1) % 2 == 1)
        return  check(b , e , b2 , e2);
    int mid = (b + e) / 2 , mid2 = (b2 + e2) / 2;
    if (ok(b , mid , b2 , mid2))
        return  ok(mid + 1 , e , mid2 + 1 , e2);
    return  ok(b , mid , mid2 + 1 , e2) && ok(mid + 1 , e , b2 , mid2);
}

int main(){
    read_fast;
    cin >> s1 >> s2;
    if (ok(0 , size(s1) - 1 , 0 , size(s2) - 1))   cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}