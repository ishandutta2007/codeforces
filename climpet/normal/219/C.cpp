#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <iterator>
#include <sstream>
#include <cstring>

using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;
typedef pair<LL,LL> pll;


int main(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    if( n == 1 ){
        cout << "0\n" << s << endl;
        return 0;
    }
    
    if( k == 2 ){
        int a1 = 0, a2 = 0;
        char next = 'A';

        for(int i = 0; i < s.size(); ++i){
            if( s[i] != next ){
                ++a1;
            }
            else{
                ++a2;
            }

            next = 'B' - next + 'A';
        }

        if( a1 <= a2 ){
            next = 'A';
        }
        else{
            next = 'B';
            a1 = a2;
        }

        for(int i = 0; i < s.size(); ++i){
            s[i] = next;
            next = 'B' - next + 'A';
        }

        cout << a1 << '\n' << s << endl;
    }
    else{
        int ans = 0;

        for(int i = s.size() - 2; i > 0; --i){
            if( s[i] == s[i + 1] ){
                for(char c = 'A'; ; ++c){
                    if( s[i-1] != c && s[i+1] != c ){
                        s[i] = c;
                        break;
                    }
                }
                ++ans;
                --i;
            }
        }
        
        if( s[0] == s[1] ){
            ++ans;
            s[0] = (s[1] == 'A' ? 'B' : 'A');
        }
        
        cout << ans << '\n' << s << endl;
    }

}