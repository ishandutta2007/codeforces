#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<complex>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

bool is_consonants(char x){
    return x != 'a' and x != 'e' and x != 'i' and x != 'o' and x != 'u';
}

int main(){
    string str;
    cin >> str;
    string tmp;
    set<char> chrs;
    for(char c:str){
        if(tmp.size() >= 2  and is_consonants(c) and is_consonants(tmp[tmp.size() - 1])
           and is_consonants(tmp[tmp.size() - 2]) and (chrs.size() >= 2 or c != tmp.back())){
            cout << tmp << " " ;
            tmp = "";
            chrs.clear();
        }
        tmp += c;
        if(!is_consonants(c))chrs.clear();
        else chrs.insert(c);
    }
    if(tmp != "")cout << tmp;
    cout << endl;
    return 0;
}