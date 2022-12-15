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
        int s,ans=0;
        cin>>s;
        while(s>=10)
        {
            ans+=s-s%10;
            s=s/10+s%10;
        }
        cout<<ans+s<<endl;
    }
    return 0;
}