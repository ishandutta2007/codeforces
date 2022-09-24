#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
const double PI = acos(-1);
const int N = 1e5;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = i ; j < n; j++)
        {
            for(int k = i; k < j + 1; k++)
            {
                a[k]++;
            }
        }
    }
    cout << *max_element(a.begin(), a.end());
    return 0;
}