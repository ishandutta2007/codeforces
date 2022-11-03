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

bool b[1111];

int main(){
    for (int i=1;i<=1100;i++)
        b[i]=0;
    int a;
    while (cin>>a){
        b[a]=true;
        char c;
        cin >> c;
    }
    int k=0;
    a=1;
    while (a<=1000){
        if (!b[a]){
            a++;
            continue;
        }
        int c=a;
        while (b[c])
            c++;
        if (k!=0)
            cout <<',';
        if (c==a+1)
            cout << a;
        else
            cout<<a<<'-'<<c-1;
        a=c;
        k=1;
    }

    return 0;
}