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
    while(T--){
        long long x;
        cin>>x;
        int i;
        long long cnt=0;
        for(i=1;cnt<=x;i++){
            long long p=1;
            p<<=i;
            p--;
            cnt+=p*(p+1)/2;
        }
        cout<<i-2<<endl;
    }
    return 0;
}