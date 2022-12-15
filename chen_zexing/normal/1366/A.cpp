#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int a,b;
        cin>>a>>b;
        cout<<min((a+b)/3,min(a,b))<<endl;
    }
    return 0;
}