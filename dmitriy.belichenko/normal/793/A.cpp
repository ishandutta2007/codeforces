#include<set>
#include<map>
#include<string>
#include<vector>
#include <iostream>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
int timer = 1;


int main()
{
    int n , k;
    vector<long long> a;
    cin >> n >> k;
    a.resize(n);
    long long sum = 0;
    long long mn = 100000000005;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        mn = min(a[i], mn);
        sum += a[i];
        
    }
    for(int i = 0; i < n; i++)
    {
        if((mn - a[i]) % k != 0)
        {
            cout << -1 << "\n";
            return  0;
        }
    }
    cout << (sum - mn  * n)/ k << "\n";
    
}