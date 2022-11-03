#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <set>

typedef long long ll;
using namespace std;

const ll mods[2] = {1e9 + 7, 1e9 + 3};

struct Hashes {
    ll hash_first;
    ll hash_second;

    Hashes() :
        hash_first(0),
        hash_second(0)
    {
    }
};

const int kMaxLen = 6e5;
const int P = 5;

ll ps[2][kMaxLen + 1];

void buildPows()
{
    for (int mod_id = 0; mod_id < 2; ++mod_id) {
        ps[mod_id][0] = 1;
        for (int i = 1; i <= kMaxLen; ++i) {
            ps[mod_id][i] = (1LL * ps[mod_id][i - 1] * P) % mods[mod_id];
        }
    }
}

ll strHash(const string& s, int mod_id) {
    ll mod = mods[mod_id];
    ll hash = 0;
    for(int i = 0; i < s.length(); ++i) {
        hash += ((s[i] - 'a' + 1) * ps[mod_id][i]) % mod;
        if (hash >= mod) {
            hash -= mod;
        }
    }
    return hash;
}


Hashes renewHash(Hashes originalHashes, int position, char currentChar, char replacementChar) {
    currentChar -= 'a' - 1;
    replacementChar -= 'a' - 1;

    ll mod_first = mods[0];
    ll mod_second = mods[1];

    Hashes newHashes = originalHashes;
    newHashes.hash_first -= ((int)currentChar * ps[0][position]) % mod_first;
    if (newHashes.hash_first < 0) {
        newHashes.hash_first += mod_first;
    }
    newHashes.hash_first += ((int)replacementChar * ps[0][position]) % mod_first;
    if (newHashes.hash_first >= mod_first) {
        newHashes.hash_first -= mod_first;
    }

    newHashes.hash_second -= ((int)currentChar * ps[1][position]) % mod_second;
    if (newHashes.hash_second < 0) {
        newHashes.hash_second += mod_second;
    }
    newHashes.hash_second += ((int)replacementChar * ps[1][position]) % mod_second;
    if (newHashes.hash_second >= mod_second) {
        newHashes.hash_second -= mod_second;
    }

    return newHashes;
}

int main() {
    buildPows();

    int n, m;

    cin >> n >> m;

    vector<string> commands(n);
    vector<string> requests(m);

    for(int i = 0; i < n; ++i) {
        cin >> commands[i];
    }
    for(int i = 0; i < m; ++i) {
        cin >> requests[i];
    }

    set<pair<ll, ll> > hashes;
    for(int i = 0; i < n; ++i) {
        hashes.insert(make_pair(strHash(commands[i], 0),
                                strHash(commands[i], 1)));
    }

    for(int j = 0; j < m; ++j) {
        string request = requests[j];
        Hashes requestHashes;
        requestHashes.hash_first = strHash(request, 0);
        requestHashes.hash_second = strHash(request, 1);
        int request_length = (int)request.length();
        bool founded = false;

        for(int k = 0; k < request_length; ++k) {
            char current_char = request[k];
            for (char new_char = 'a'; new_char <= 'c'; ++new_char) {
                if (current_char != new_char) {
                    Hashes newRequestHashes = renewHash(requestHashes, k, current_char, new_char);
                    if (hashes.find(make_pair(newRequestHashes.hash_first, newRequestHashes.hash_second)) != hashes.end()) {
                        founded = true;
                        break;
                    }
                }
            }
        }

        if(founded) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}