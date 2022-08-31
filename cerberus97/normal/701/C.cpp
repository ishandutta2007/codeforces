#include <iostream>
#include <set>
#include <map>

using namespace std;

set <char> pokemonList;
map <char, int> cur;
char s[100005];

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n >> s;

    for (int i = 0; i < n; ++i)
        pokemonList.insert(s[i]);

    unsigned int total = pokemonList.size();
    int l = 0, r = 0, ans = 1e6;
    cur[s[0]] = 1;

    while (r < n)
    {
        if (cur.size() < total)
        {
            ++r;

            if (cur.find(s[r]) == cur.end())
                cur[s[r]] = 1;

            else
                cur[s[r]]++;
        }

        else
        {
            ans = min(ans, r-l+1);

            if (cur[s[l]] == 1)
                cur.erase(s[l]);

            else
                cur[s[l]]--;

            ++l;
        }
    }

    cout << ans;

    return 0;
}