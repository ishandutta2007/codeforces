#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
int n,m,s,x,l,r,i,j;
vector<int> can;
int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>x;
        s+=x;
    }
    cin>>m; 
    for (i=1;i<=m;i++)
    {
        cin>>l>>r;
        for (j=l;j<=r;j++)
        {
            can.push_back(j);
        }
    }
    if (binary_search(can.begin(),can.end(),s)) cout<<s;
    else
    {
        if (upper_bound(can.begin(),can.end(),s-1)!=can.end()) cout<<*upper_bound(can.begin(),can.end(),s-1);
        else cout<<-1;
    }
    return 0;
}