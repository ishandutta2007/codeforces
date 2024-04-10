#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int NMAX = 211111;

char stack[NMAX];
int size = 0;
string s;

int main(){
    cin >> s;
    for (int i=0;i<s.length();i++)
        if (size>0 && stack[size]==s[i])
            size--;
        else stack[++size]=s[i];
    for (int i=1;i<=size;i++)
        cout << stack[i];
    return 0;
}