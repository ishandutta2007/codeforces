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
    string s;
    cin>>s;
    if(s.size()%2==0) printf("%d\n",s.size()/2); 
    else{
        int f=0;
        for(int i=1;i<s.size();i++)
            if(s[i]=='1')
                f=1;
        if(f) cout<<s.size()/2+1<<endl;
        else cout<<s.size()/2<<endl;
    }
    return 0;
}