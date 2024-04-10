#include <queue>
#include <iostream>
#include <vector>
using namespace std;
struct cmp
{
    bool operator()(int a,int b)
    {
        return a < b;
    }
};
int main()
{
    priority_queue<int,vector<int>,cmp> Q;
    int n,t,sum = 0;
    cin >> n;
    for(int k = 0;k < n; k++)
    {
        cin >> t;
        sum += t;
        Q.push(t);
    }
    int now = 0,cnt = 0;
    while(now <= sum/2)
    {
        //cout << "top is " << Q.top() << endl;
        cnt++;
        now += Q.top();
        Q.pop();
    }
    cout << cnt << endl;
    return 0;
}