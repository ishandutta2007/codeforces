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
string s;
int main() {
    int n,k;
    cin>>n>>k;
    cout<<n<<endl;
    cin>>s;
    string t="";
    for(int i=0;i<n;i++) t+=s[i%k];
    if(t>=s){
        cout<<t<<endl;
        return 0;
    }
    s[k-1]++;
    for(int i=k-1;i>=0;i--){
        if(s[i]>'9') s[i]-=10,s[i-1]++;
    }
    t="";
    for(int i=0;i<n;i++) t+=s[i%k];
    cout<<t<<endl;
    return 0;
}