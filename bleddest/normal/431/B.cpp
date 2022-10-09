#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 5;

int ans;
int a[N][N];


int main()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> a[i][j];
    vector<int> p(N);
    for(int i = 0; i < N; i++)
        p[i] = i;
    do
    {
        int cur = 0;
        for(int i = 0; i < N; i++)
            for(int j = i; j < N; j += 2)
                if(j < N - 1)
                    cur += a[p[j]][p[j + 1]] + a[p[j + 1]][p[j]];
        ans = max(cur, ans);
    }
    while(next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    return 0;
}