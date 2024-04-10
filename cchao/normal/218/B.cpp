#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct cp1
{
    bool operator()(int a,int b)
    {
        return a > b;
    }
};
struct cp2
{
    bool operator()(int a,int b)
    {
        return a < b;
    }
};
int main()
{
    int n,m,t;
    cin >> n >> m;
    priority_queue<int,vector<int>,cp1> a;
    priority_queue<int,vector<int>,cp2> b;
    for(int k = 0; k < m; k++)
    {
        cin >> t;
        a.push(t);
        b.push(t);
    }
    t = n;
    int a1 = 0, a2 = 0,tmp;
    while(t-- && a.size())
    {
        tmp = a.top();
        a1 += tmp;
        a.pop();
        if(tmp > 1)a.push(tmp-1);
    }
    t = n;
    while(t-- && b.size())
    {
        tmp = b.top();
        a2 += tmp;
        b.pop();
        if(tmp > 1) b.push(tmp-1);
    }
    cout << a2 << ' ' << a1 << endl;
    return 0;
}