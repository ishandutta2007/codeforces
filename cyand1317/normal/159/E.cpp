//  ( -)
#include <cstdio>
#include <algorithm>
#include <functional>
#include <map>
#include <tuple>
#include <vector>
typedef long long int64;
static const int MAXN = 1e5 + 4;

int n;
typedef std::map<int, std::vector<std::pair<int, int>>> cubes_t;
cubes_t cubes;  // Pyramids  
std::pair<int64, int> single[MAXN];

int main()
{
    scanf("%d", &n);
    int c_i, s_i;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &c_i, &s_i);
        cubes[c_i].push_back({ s_i, i });
    }
    for (auto &kv : cubes)
        std::sort(kv.second.begin(), kv.second.end(), std::greater<std::pair<int, int>>());

    for (int i = 0; i <= n; ++i) single[i] = { -1LL << 61, -1 };
    // tuple<answer_value, first_colour, first_count, second_colour, second_count>
    auto best = std::make_tuple(-1LL, -1, -1, -1, -1);
    for (auto kv : cubes) {
        /*printf("=== Colour %d ===\n", kv.first);
        for (auto val : kv.second) printf(" %d", val.first); putchar('\n');
        for (int i = 0; i < n; ++i)
            printf("%d same-colour cubes: %lld (achieved by colour %d)\n", i + 1, single[i].first, single[i].second);*/
        int64 sum = 0;
        for (int i = 0; i < (int)kv.second.size(); ++i) {
            sum += kv.second[i].first;
            // pair<pair<single_value, single_colour>, single_count>
            auto sel = std::max<std::pair<std::pair<int64, int>, int>>({ single[i], i }, { single[i + 1], i + 1 });
            if (i > 0) sel = std::max(sel, { single[i - 1], i - 1 });
            auto cur = std::make_tuple(sum + sel.first.first, sel.first.second, sel.second, kv.first, i);
            best = std::max(best, cur);
        }
        sum = 0;
        for (int i = 0; i < (int)kv.second.size(); ++i)
            single[i] = std::max(single[i], { sum += kv.second[i].first, kv.first });
    }

    printf("%I64d\n%d", std::get<0>(best), std::get<2>(best) + std::get<4>(best) + 2);
    int starting_colour, starting_count;
    std::tie(starting_colour, starting_count) =
        (std::get<2>(best) >= std::get<4>(best) ?
        std::make_pair(std::get<1>(best), std::get<2>(best)) :
        std::make_pair(std::get<3>(best), std::get<4>(best)));
    int alternating_colour = std::get<1>(best) ^ std::get<3>(best) ^ starting_colour,
        alternating_count = std::get<2>(best) ^ std::get<4>(best) ^ starting_count;
    auto &starting_cubes = cubes[starting_colour];
    auto &alternating_cubes = cubes[alternating_colour];
    bool first = true;
    for (int i = 0; i <= starting_count; ++i) {
        printf("%c%d", first ? '\n' : ' ', starting_cubes[i].second + 1);
        if (i <= alternating_count) printf(" %d", alternating_cubes[i].second + 1);
        first = false;
    }
    putchar('\n');
    return 0;
}