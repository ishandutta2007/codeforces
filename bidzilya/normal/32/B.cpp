#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <iterator>
using namespace std;

int main(){
    string s;
    cin >> s;
    for (int i=0;i<s.length();)
        if (s[i]=='.'){
            cout << 0;
            i++;
        }
        else
        if (i+1<s.length() && s[i]=='-' && s[i+1]=='.'){
            cout << 1;
            i += 2;
        }
        else
        if (i+1<s.length() && s[i]=='-' && s[i+1]=='-'){
            cout << 2;
            i += 2;
        }

        return 0;
}