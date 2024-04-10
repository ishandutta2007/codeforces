#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef pair<char,int> pci;

int ccc[100010];
int dep[100010];

int main(){
    ios::sync_with_stdio(false);

    memset(dep, -1, sizeof dep);

    string s;
    cin >> s;

    int *c = ccc + 1;
    deque<char> st;
    int d = 0;
    
    int maxc = 0;
    int a = 0;
    int b = 0;
    
    for(int i = 0; i < s.size(); ++i){

        c[i] = c[i-1];

        switch( s[i] ){
            case '[':
                st.push_back(s[i]);
                ++c[i];
                if( dep[d] == -1 ) dep[d] = i;
                ++d;
                break;
            case ']':
                if( !st.empty() ){
                    char p = st.back();
                    st.pop_back();

                    if( p != '[' ){
                        st.clear();
                        fill(dep, dep + d + 1, -1);
                        d = 0;
                    }
                    else{
                        dep[d] = -1;
                        int x = dep[--d];
                        if( c[i] - c[x-1] > maxc ){
                            maxc = c[i] - c[x-1];
                            a = x;
                            b = i + 1;
                        }
                    }
                }
                else{
                    dep[0] = -1;
                }
                break;
            case '(':
                if( dep[d] == -1 ) dep[d] = i;
                ++d;
                st.push_back(s[i]);
                break;
            case ')':
                if( !st.empty() ){
                    if( st.back() != '(' ){
                        st.clear();
                        fill(dep, dep + d + 1, -1);
                        d = 0;
                    }
                    else{
                        dep[d] = -1;
                        int x = dep[--d];
                        st.pop_back();
                        
                        if( c[i] - c[x-1] > maxc ){
                            maxc = c[i] - c[x-1];
                            a = x;
                            b = i + 1;
                        }
                    }
                }
                else{
                    dep[0] = -1;
                }
                break;
        }
    }
    
    cout << maxc << '\n' << string(s.begin() + a, s.begin() + b) << '\n';
}