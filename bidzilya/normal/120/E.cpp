#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int t,n;
    for (cin>>t;t;t--)
    {
        cin >> n;
        cout << (n+1)%2 << endl;
    }
    return 0;
}