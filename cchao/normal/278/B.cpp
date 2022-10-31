#include <cstdio>
#include <iostream>
#include <set>
#include <queue>
using namespace std;
set<string> f;
char d[30];

string bfs(){
    queue<string> q;
    for(int i = 'a'; i <= 'z'; ++i){
        d[0]=i;
        if(f.count(d)<=0) return d;
        q.push(d);
    }
    while(q.size()){
        string x = q.front();
        if(f.count(x) <= 0) return x;
        q.pop();
        for(int i = 'a'; i <= 'z'; ++i){
            string t = x;
            t.push_back(i);
            q.push(t);
        }
    }
}
int main(){
    int n; string s;
    cin >> n;
    while(n--){
        cin >> s;
        for(int len = 1; len <= s.length(); ++len)
            for(int i = 0; i + len -1 < s.length(); ++i){
                char t[30]={0};
                for(int j = 0; j < len; ++j)
                    t[j] = s[j+i];
                f.insert(t);
            }
    }
    cout << bfs() << endl;
    return 0;
}