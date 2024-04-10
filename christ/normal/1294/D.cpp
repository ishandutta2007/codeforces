#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q, x;
    scanf("%i%i", &q, &x);
    set<pair<int,int>> arr;
    vector<int> cnt(x);
    for (int i = 0; i < x; i++)
        arr.insert({0, i});
    while (q--)
    {
        int y;
        scanf("%i", &y);
        y %= x;
        arr.erase(arr.find({cnt[y], y}));
        cnt[y]++;
        arr.insert({cnt[y], y});
        auto cur = *arr.begin();
        printf("%i\n", cur.first * x + cur.second);
    }
}