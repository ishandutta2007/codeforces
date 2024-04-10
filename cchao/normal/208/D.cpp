#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
using namespace std;
#define sz size()
#define mp(a,b) make_pair(a,b)
#define LOOP(_index,_times) for(int _index = 0; _index<_times;_index++)
#define FOR(_index,_start,_end) for(int _index=_start;_index<_end;_index++)
#define FORE(_index,_start,_end) for(int _index=_start;_index<=_end;_index++)
long long int c[5];
int cmp(long long int a,long long int b)
{
    return c[a] > c[b];
}
int main()
{
    long long int n;
    cin >> n;
    long long int m[n];
    for(int k=0;k<n;k++) cin >> m[k];
    long long int v[5];
    for(int k=0;k<5;k++)
    {
        cin >> c[k];
        v[k] = k;
    }
    sort(v,v+5,cmp);
    long long int sum = 0;
    long long int cnt[5] = {0};
    for(int k=0;k<n;k++)
    {
        sum += m[k];
        int j = 0;
        for(j=0;j<5;j++)
        {
            int tmp = v[j],tmp2;
//            cout << "--" <<  tmp << endl;
            tmp2 = sum / c[tmp];
            cnt[tmp] += tmp2;
            sum -= tmp2 * c[tmp];
        }
    }
    for(int k=0;k<5;k++)
        cout << cnt[k] << ' ';
    cout << endl;
    cout << sum << endl;
    return 0;
}