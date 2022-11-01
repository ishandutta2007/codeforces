#include <iostream>
#include <string>
#include <set>
#include <utility>
using namespace std;

typedef unsigned long long ull;
typedef pair<ull,ull> puu;

const ull p1 = 1000000007, p2 = 1000000009;

int main(){
    string s, good;
    int k;
    cin >> s >> good >> k;

    set<puu> st;
    int ans = 0;
    for(int i = 0; i < s.size(); ++i){
        int c = 0;
        puu hash;
        for(int j = i; j < s.size(); ++j){
            if(good[s[j]-'a'] == '0'){
                if(++c > k) break;
            }

            int a = s[j] - 'a' + 1;
            hash.first = hash.first * p1 + a;
            hash.second = hash.second * p2 + a;
            if(st.insert(hash).second){
                ++ans;
            }
        }
    }
    
    cout << ans << endl;
}