#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <ctime>

using namespace std;

bool cons[256];
int n,k;
vector < string > v;

bool ok(int i,int j)
{
    int ind1=v[i].size(),ind2=v[j].size(),cnt1=0,cnt2=0;
    while(ind1>0&&cnt1<k)
    {
        ind1--;
        cnt1+=cons[v[i][ind1]];
    }
    while(ind2>0&&cnt2<k)
    {
        ind2--;
        cnt2+=cons[v[j][ind2]];
    }
    if (cnt1!=k||cnt2!=k) return false;
    return v[i].substr(ind1)==v[j].substr(ind2);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    cin >> n >> k;
    cons['a']=cons['e']=cons['i']=cons['o']=cons['u']=true;
    bool what[4]={0};
    for(int i=0;i<n;i++)
    {
        v.clear();
        v.resize(4);
        cin >> v[0] >> v[1] >> v[2] >> v[3];
        if (ok(0,1)&&ok(1,2)&&ok(2,3)) {} else what[3]=true;
        if (ok(0,1)&&ok(2,3)) {} else what[0]=true;
        if (ok(0,2)&&ok(1,3)) {} else what[1]=true;
        if (ok(0,3)&&ok(2,1)) {} else what[2]=true;
    }
    if (!what[3])
    {
        cout << "aaaa\n";
        return 0;
    }
    if (!what[0])
    {
        cout << "aabb\n";
        return 0;
    }
    if (!what[1])
    {
        cout << "abab\n";
        return 0;
    }
    if (!what[2])
    {
        cout << "abba\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}