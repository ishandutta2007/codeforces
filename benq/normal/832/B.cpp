#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

int N,starlength, starpos = -1;
string goods, patt, query;

int main() {
    cin >> goods >> patt >> N;
    F0R(i,patt.length()) if(patt[i] == '*') starpos = i;

    F0R(i,N) {
        cin >> query;
        int match = 1;
        if(starpos != -1){
            if(query.length() >= patt.length()-1){
                starlength = query.length()-patt.length()+1;
                F0R(j,query.length()) {
                    if(j < starpos){
                        if(patt[j] != '?') {
                            if(patt[j] != query[j]) match = 0;
                        } else {
                            int d = 0;
                            F0R(q,goods.length()) if(goods[q] == query[j]) d = 1;
                            if(d == 0) match = 0;
                        }
                    } else if (j >= starpos && j < starpos + starlength){
                        F0R(r,goods.length()) if(query[j] == goods[r]) match = 0;
                    } else {
                        if (patt[j-starlength+1] != '?'){
                            if (patt[j-starlength+1] != query[j]) match = 0;
                        } else {
                            int d = 0;
                            F0R(q,goods.length()) if(goods[q] == query[j]) d = 1;
                            if(d == 0) match = 0;
                        }
                    }
                }
            } else match = 0;
        } else {
            if (query.length() == patt.length()) {
                F0R(j,query.length()) {
                    if (patt[j] != '?'){
                        if(patt[j] != query[j]) match = 0;
                    } else {
                        int d = 0;
                        F0R(q,goods.length()) if(goods[q] == query[j]) d = 1;
                        if(d == 0) match = 0;
                    }
                }
            } else match = 0;
        }
        if (match) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}