#include <bits/stdc++.h>

using namespace std;

void test(int cnt[4], int flip)
{
    deque<int> arr;
    auto get = [&](int a){
        return flip ? 3 - a : a;
    };
    auto add = [&](int k){
        arr.push_back(get(k));
        cnt[k]--;
        assert(cnt[k] >= 0);
    };
    while (cnt[3] && cnt[2])
    {
        add(3);
        add(2);
    }
    while (cnt[2] && cnt[1])
    {
        add(1);
        add(2);
    }
    while (cnt[1] && cnt[0])
    {
        add(1);
        add(0);
    }
    if (cnt[2] && (arr.empty() || abs(get(2)-arr.front()) == 1))
        arr.push_front(get(2));
    if (cnt[3] && (arr.empty() || abs(get(3)-arr.back()) == 1))
        add(3);
    if (cnt[1] && (arr.empty() || abs(get(1)-arr.back()) == 1))
        add(1);
    if (cnt[0] && (arr.empty() || abs(get(0)-arr.back()) == 1))
        add(0);
    for (int x = 0; x < 4; x++)
        if (cnt[x])
            return;
    printf("YES\n");
    for (auto &x : arr)
        printf("%i ", x);
    printf("\n");
    exit(0);
}

int main()
{
    int other[4], cnt[4];
    for (int x = 0; x < 4; x++)
        scanf("%i", &cnt[x]), other[3-x] = cnt[x];
   test(cnt, 0);
   test(other, 1);
   printf("NO\n");
}