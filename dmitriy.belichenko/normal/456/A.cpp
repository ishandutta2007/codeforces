#include<vector>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<set>
#include<map>
#include<iomanip>
#include<string>
#include<iostream>
#include<math.h>
#define count count1557
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;



int main()
{
   

    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int , int>> a(n);
    vector<pair<int , int>> b(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
        cin >> b[i].first;
        b[i].second = i;

    }
 
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(),b.rend());
    for(int i = 0; i < n; i++)
    {
        if(a[i].second!= b[i].second)
        {
            cout << "Happy Alex" << endl;
            return 0;
        }
    }
    cout <<"Poor Alex" << endl;
    return 0;
}