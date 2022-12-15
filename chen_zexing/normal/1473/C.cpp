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
priority_queue<int>q;
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<k*2-n;i++) printf("%d ",i);
        for(int i=k;i>=k*2-n;i--) printf("%d ",i);
        puts("");
    }
    return 0;
}