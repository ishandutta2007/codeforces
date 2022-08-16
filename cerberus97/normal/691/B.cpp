#include <iostream>
#include <cstring>

using namespace std;

char mirror[200] = {0}, s[1005];

void setMirrors()
{
    mirror['A'] = 'A';
    mirror['b'] = 'd';
    mirror['d'] = 'b';
    mirror['H'] = 'H';
    mirror['I'] = 'I';
    mirror['M'] = 'M';
    mirror['O'] = 'O';
    mirror['o'] = 'o';
    mirror['p'] = 'q';
    mirror['q'] = 'p';
    mirror['T'] = 'T';
    mirror['U'] = 'U';
    mirror['V'] = 'V';
    mirror['v'] = 'v';
    mirror['w'] = 'w';
    mirror['W'] = 'W';
    mirror['X'] = 'X';
    mirror['x'] = 'x';
    mirror['Y'] = 'Y';
}

bool isPal(char *s)
{
    int len = strlen(s);

    for (int i = 0, j = len-1; i <= j; ++i, --j)
        if (s[i] != mirror[s[j]])
            return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    setMirrors();

    cin >> s;

    if (isPal(s))
        cout << "TAK";

    else
        cout << "NIE";

    return 0;
}