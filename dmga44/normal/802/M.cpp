#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);

//    freopen(".in","r",stdin);

    int N,K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0;i < N;i++)
        cin >> A[i];

    stable_sort(A.begin(),A.end());

    int sol = 0;
    for(int i = 0;i < K;i++)
        sol += A[i];

    cout << sol << '\n';

    return 0;
}