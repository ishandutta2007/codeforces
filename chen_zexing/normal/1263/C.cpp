#include <stdio.h>
#include <iostream>
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
vector <int> v;
int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        v.clear();
        v.push_back(0);
        for(int i=1;i*i<=n;i++){
            v.push_back(i);
            if(n/i!=i) v.push_back(n/i);
        }
        printf("%d\n",v.size());
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++) printf("%d ",v[i]);
        puts("");
    }
    return 0;
}