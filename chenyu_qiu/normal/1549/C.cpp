#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<int> st(N,0);
int n,m,q,cnt;

void add(int a,int b)
{
    if(st[a] == 0 && a < b) cnt ++;
    else if(st[b] == 0 && a > b) cnt ++;

    if (a < b) st[a] ++;
    else if(a > b) st[b] ++;
}
void remove_edge(int a,int b)
{
    if(st[a] - 1 == 0 && a < b) cnt --;
    else if(st[b] - 1 == 0 && a > b) cnt --;

    if(a < b) st[a] --;
    else if(a > b) st[b] --;
}
int main()
{
    cin >> n >>m;

    while(m -- ){
        int a,b;
        cin >> a >> b;
        add(a,b);
    }

    cin >> q;
    while(q -- ){
        int t;
        cin >> t;
        if(t == 1){
            int a,b;
            cin >> a >>b;
            add(a,b);
        }else if(t == 2){
            int a,b;
            cin >> a >> b;
            remove_edge(a,b);
        }else{
            cout << n - cnt <<'\n';
        }
    }

    return 0;
}