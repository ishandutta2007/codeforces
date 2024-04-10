#include <bits/stdc++.h>
using namespace std;

string a , b;
int sum = 0 , goal , all , good = 0;
void DFS(int ts , int now){
    if(ts == sum){
        all ++;
        if(now == goal) good ++;
    }
    else {
        DFS(ts + 1 , now + 1);
        DFS(ts + 1 , now - 1);
    }
}
int32_t main(){
    cin >> a >> b;
    int acnt = 0 , bcnt = 0;
    for(int i = 0 ; i < a.size() ; i ++)
        acnt += (a[i] == '+') ? 1 : -1;
    for(int i = 0 ; i < b.size() ; i ++){
        if(b[i] == '?') sum ++;
        else bcnt += (b[i] == '+') ? 1 : -1;
    }
    goal = acnt - bcnt;
    DFS(0 , 0);
    double ans = (double)good / all;
    printf("%.010lf\n", ans);
    return 0;
}