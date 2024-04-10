//
//  main.cpp
//  codegorces
//
//  Created by Dmitry Belichenko on 23.02.17.
//  Copyright  2017 Dmitry Belichenko. All rights reserved.
//

#include<iostream>
#include<set>
#include <map>
#include <vector>
#include<string>
using namespace std;
bool pri(int k)
{
    if (k == 1) return false;
    for (int i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return true;
}
long gcd(long a, long b)
{
    if (b == 0)
    {
        return a;
    }
    
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> colors(n);
    vector<int> cost(n);
    vector<int> primes;
     int mxx[100005];
    for(int i = 0; i < n; i++)
    {
        
        cost[i] = i + 2;
        if( pri(cost[i]))
        {
            primes.push_back(cost[i]);
            colors[i] = 1;
        }
        else colors[i] = 2;
        mxx[i] = 0;
    }
   
    int ans = 1;
    for(int i = 0; i < primes.size(); i++)
    {
        for(int j = 0; j < cost.size(); j++)
        {
            if(cost[j] % primes[i] == 0)
            {
                mxx[primes[i]]++;
                ans = max(mxx[primes[i]], ans);
            }
        }
    }
    if(n != 1 && n != 2)
    cout << 2 << endl;
    else cout<< 1 << endl;
    for(int i = 0; i < n; i++)
        cout << colors[i] << " ";
    
    
}