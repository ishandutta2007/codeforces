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
using namespace std;
int main() {
    int n;
    cin>>n;
    printf("2 3\n");
    int t=n,x=0;
    while(t){
        t/=2;
        x++;
    }
    int a,b,c,d,e,f;
    a=(1<<(x+1))-1,d=n,b=a-d,e=a,c=0,f=n;
    cout<<a<<" "<<b<<" "<<c<<endl;
    cout<<d<<" "<<e<<" "<<f<<endl;
    return 0;
}