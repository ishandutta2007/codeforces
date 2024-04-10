#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        long long d,k;
        cin>>d>>k;
        long long t=sqrt(double(d*d)/(k*k)*0.5);
        if(t*t*k*k+(t+1)*(t+1)*k*k<=d*d) puts("Ashish");
        else puts("Utkarsh");
    }
    return 0;
}