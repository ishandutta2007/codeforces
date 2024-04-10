#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
struct node{
    int id,v;
    friend bool operator <(node a,node b){
        return a.v>b.v||a.v==b.v&&a.id<b.id;
    }
};
set <node> s;
vector <pair<int,int>> v;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        s.clear(),v.clear();
        for(int i=1,x;i<=n;i++) {
            scanf("%d", &x);
            if (x) s.insert(node{i, x});
        }
        while(s.size()>=2){
            auto p1=*s.begin();
            //cout<<p1.id<<" "<<p1.v<<endl;
            s.erase(s.begin());
            auto p2=*s.begin();
            //cout<<p2.id<<" "<<p2.v<<endl;
            s.erase(s.begin());
            //cout<<"#"<<s.size()<<endl;
            v.push_back(make_pair(p1.id,p2.id));
            if(p1.v>1) s.insert(node{p1.id,p1.v-1});
            if(p2.v>1) s.insert(node{p2.id,p2.v-1});
            //cout<<"?"<<s.size()<<endl;
        }
        printf("%d\n",v.size());
        for(auto t:v) printf("%d %d\n",t.first,t.second);
    }
    return 0;
}
//
/// 
//01
//