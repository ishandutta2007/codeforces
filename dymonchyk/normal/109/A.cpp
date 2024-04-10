#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for(int i=0;4*i<=n;i++)
    {
        int s=(n-4*i)/7;
        if (4*i+7*s==n)
        {
            for(int j=0;j<i;j++)
                printf("4");
            for(int j=0;j<s;j++)
                printf("7");
            printf("\n");
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}