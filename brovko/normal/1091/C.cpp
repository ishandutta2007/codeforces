#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long n;
vector <long long> v;

int main()
{
    cin >> n;
    for(long long i=1;i*i<=n;i++)
        if(n%i==0)
    {
        v.push_back((n-i+2)*(n/i)/2);
        if(i*i!=n)
        v.push_back((n-n/i+2)*i/2);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++)
        cout << v[i] << ' ';
    return 0;
}