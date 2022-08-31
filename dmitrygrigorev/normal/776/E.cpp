#include <bits/stdc++.h>
using namespace std;
long long n, k;
const int CONST = 1000010;
vector<long long> primes;
long long ec(long long np){
    int counter = 0;
    long long euler = 1;
    for (int i=0;i<primes.size(); i++){
        if (np == 1) break;
        while (np % primes[i] == 0){
            np = np / primes[i];
            counter += 1;
        }
        if (counter > 0){
            long long one = pow(primes[i], counter);
            long long two = one / primes[i];
            long long three = one - two;
            euler = euler * three;
        }
        counter = 0;
    }
    if (np > 1){
        euler = euler * (np - 1);
    }
    return euler;
}
bool erat[CONST];
int main()
{
    for (int i=2;i<CONST;i++){
        erat[i] = true;
    }
    for (int i=2;i<CONST;i++){
        if (erat[i]){
            primes.push_back(i);
            for (int j=i+i;j<CONST;j+=i){
                erat[j] = false;
            }
        }
    }
    cin >> n >> k;
    for (int i=0;i<k;i+=2){
        n = ec(n);
        if (n == 1){
            cout << 1 << endl;
            return 0;
        }
    }
    cout << (n % 1000000007) << endl;
    return 0;
}