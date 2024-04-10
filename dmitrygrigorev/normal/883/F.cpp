#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
#define int long long
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    set<string> ms;
    for (int i=0; i < n; i++){
        string s;
        cin >> s;
        string ns = "";
        for (int j=0; j < s.size(); j++){
            if (s[j] == 'u') ns += "oo";
            else if (s[j] == 'h'){
                while (ns.size() > 0 && ns[ns.size() - 1] == 'k'){
                    string real = "";
                    for (int k=0; k < ns.size() - 1; k++){
                        real += ns[k];
                    }
                    ns = real;
                }
                ns += 'h';
            }
            else ns += s[j];
        }
        ms.insert(ns);
    }
    cout << ms.size() << endl;
    return 0;
}