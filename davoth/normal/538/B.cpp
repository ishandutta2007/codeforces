#include <bits/stdc++.h>
using namespace std;
const int si=1e5+10;
int main()
{
    int N;
    cin >> N;
    vector<int> a;
    while (N) {
        int n = N, m = 0, p = 1;
        while (n) {
            if (n % 10) m += p;
            n /= 10; p *= 10;
        }
        a.push_back(m);
        N -= m;
    }
    cout << a.size() <<"\n";
    sort(a.begin(),a.end());
    for (int x=0;x<a.size();x++) cout << a[x] <<" ";

    return 0;
}