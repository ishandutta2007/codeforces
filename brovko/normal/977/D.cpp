#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long n, a[100];
vector < pair < pair <long long, long long> , long long > > b;
int stepen2(long long val)
{
    int k=0;
    while(val%2==0)
    {
        val=val/2;
        k++;
    }
    return k;
}
int stepen3(long long val)
{
    int k=0;
    while(val%3==0)
    {
        val=val/3;
        k--;
    }
    return k;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        b.push_back(make_pair(make_pair (stepen2(a[i]), stepen3(a[i]) ), a[i]));
    sort(b.begin(), b.end());
    for(int i=0;i<n;i++)
        cout << b[i].second << ' ';
    return 0;
}