#include <stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
#define LL long long
#define MAX 100005

using namespace std;
int main() {
    long long a1,a2,a3,b1,b2,b3,n,m;
    cin>>n;
    cin>>a1>>a2>>a3;
    cin>>b3>>b1>>b2;
    long long ans1=0,ans2=0;
    ans2=min(a1,b1)+min(a2,b2)+min(a3,b3);
    ans1=max(ans1,a1-b2-b3);
    ans1=max(ans1,a2-b1-b3);
    ans1=max(ans1,a3-b1-b2);
    ans1=max(ans1,b1-a2-a3);
    ans1=max(ans1,b2-a1-a3);
    ans1=max(ans1,b3-a1-a2);
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}