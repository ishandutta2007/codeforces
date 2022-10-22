#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;
typedef pair<P, Int> T;

void ok(){
    cout << "YES" << endl;
    exit(0);
}

void ng(){
    cout <<  "NO" << endl;
    exit(0);
}


Int n;
P s[324000], t[324000];
vector<int> p, m;
vector<T> queries;
Int mv = 0;
int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> s[i].first;
        s[i].second = i + 1;
    }
    for(int i = 0;i < n;i++){
        cin >> t[i].first;
        t[i].second = i + 1;
    }
    sort(s, s + n);
    sort(t, t + n);

    for(int i = 0;i < n;i++){
        if(s[i].first < t[i].first)p.push_back(i);
        if(s[i].first > t[i].first)m.push_back(i);
        mv += t[i].first - s[i].first;
    }
    if(mv != 0)ng();

    while(!p.empty()){
        int i = p.back();
        int j = m.back();
        if(s[i] > s[j])ng();
        int d = min(t[i].first - s[i].first, s[j].first - t[j].first);
        queries.push_back(T(P(i, j), d));
        s[i].first += d;
        s[j].first -= d;
        if(s[i].first == t[i].first)p.pop_back();
        if(s[j].first == t[j].first)m.pop_back();
    }
    cout << "YES" << endl;
    printf("%d\n", (int)queries.size());
    for(auto t:queries){
        Int i = t.first.first;
        Int j = t.first.second;
        Int d = t.second;
        printf("%lld %lld %lld\n", s[i].second, s[j].second, d);
    }
    
    return 0;
}