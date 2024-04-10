#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<char> prime(n + 2, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i <= n + 1; i++)
        if(prime[i])
            for(long long j = i * 1ll * i; j <= n + 1; j += i)
                prime[j] = false;

    cout << (n <= 2 ? 1 : 2) << endl;
    for(int i = 0; i < n; i++)
        cout << (prime[i + 2] ? 1 : 2) << " ";
}