#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char *n;
    n = new char[1048576];
    cin >> n;
    switch (n[(int)strlen(n) - 2])
    {
        case '1':
        case '3':
        case '5':
        case '7':
        case '9':
            switch (n[(int)strlen(n) - 1])
            {
                case '2':
                case '6':
                    cout << 4 << endl;
                    break;
                default:
                    cout << 0 << endl;
            }
            break;
        default:
            switch (n[(int)strlen(n) - 1])
            {
                case '0':
                case '4':
                case '8':
                    cout << 4 << endl;
                    break;
                default:
                    cout << 0 << endl;
            }
            break;
    }
    return 0;
}