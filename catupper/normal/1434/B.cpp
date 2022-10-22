#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using Int = long long;
using Real = long double;
using CP = complex<Real>;
using P = pair<Int, Int>;

const Int MOD = 1000000007;
const Int MOD2 = 998244353;
const Int LINF = (1LL << 60);
const int INF = (1000000007);
const Real EPS = 1e-10;
const long double PI = 3.141592653589793238462643383279502884L;

vector<int> events;
void ok(){
    cout << "YES" << endl;
    exit(0);
}

void ng(){
    cout <<  "NO" << endl;
    exit(0);
}


int main()
{
    int n, x;
    scanf("%d", &n);
    for(int i = 0;i < 2*n;i++){
        char c;
        scanf(" %c", &c);
        if(c == '+')events.push_back(0);
        else{
            scanf("%d", &x);
            events.push_back(x);
        }        
    }
    reverse(events.begin(), events.end());

    set<int> show_case;
    vector<int> ans;
    for(auto e:events){
        if(e == 0){
            if(show_case.empty())ng();            
            ans.push_back(*show_case.begin());
            show_case.erase(show_case.begin());
        }
        else{
            if(!show_case.empty() && *show_case.begin() < e)ng();
            show_case.insert(e);
        }
    }
    puts("YES");
    reverse(ans.begin(), ans.end());
    for(auto a:ans)printf("%d ",a);
    puts("");
    return 0;
}