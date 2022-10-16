#include <iostream>
#include <set>

using namespace std;

char s[200][200];

int main()
{
    int n, m;
    char R;
    cin >> n >> m >> R;
    
    for (int i = 0; i < n; i++) cin >> (s[i+1] + 1);
    
    set<char> res;
    
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (s[i][j] == R)
    {
        if (s[i-1][j] != R && s[i-1][j] != '.' && s[i-1][j] != 0) res.insert(s[i-1][j]);
        if (s[i+1][j] != R && s[i+1][j] != '.' && s[i+1][j] != 0) res.insert(s[i+1][j]);
        if (s[i][j-1] != R && s[i][j-1] != '.' && s[i][j-1] != 0) res.insert(s[i][j-1]);
        if (s[i][j+1] != R && s[i][j+1] != '.' && s[i][j+1] != 0) res.insert(s[i][j+1]);
    }
    
    cout << res.size() << endl;
    return 0;
}