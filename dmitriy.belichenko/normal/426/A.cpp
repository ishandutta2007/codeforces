#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
int n , m;

int main()
{
    cin >> n >> m;
    long long sum = 0;
    int mx = -1;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mx = max(x , mx);
        sum+= x;
    }
    if(sum > m + mx) cout << "NO";
    else cout <<"YES";
}