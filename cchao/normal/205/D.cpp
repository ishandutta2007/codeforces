#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int thre;
    if(n%2==0)
    {
        thre = n/2;
    }
    else
    {
        thre = n/2 + 1;
    }
    map<int,int> front,total;
    int a,b;
    for(int k=0;k<n;k++)
    {
        cin >> a >> b;
        if(front.count(a)<=0)
            front[a] = 1;
        else
            front[a] ++;
        if(total.count(a) <= 0)
            total[a] = 1;
        else
            total[a] ++;
        if(a!=b)
        {
            if(total.count(b) <= 0)
                total[b] = 1;
            else
                total[b] ++;
        }
    }
    map<int,int>::iterator it;
    int findans = 0,ans=2147483647;
    for(it = total.begin();it!=total.end();it++)
    {
        if(it->second >= thre)
        {
            findans = 1;
            a = front[it->first];
            if(a>=thre)
            {
                ans = 0;
                break;
            }
            if(thre - a < ans)
            {
                ans = thre - a;
            }
        }
    }
    if(findans==1)
    {
        cout << ans << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}